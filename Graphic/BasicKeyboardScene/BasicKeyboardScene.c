#include "BasicKeyboardScene.h"

static const char	*keys[] =
  {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "q",
    "w",
    "e",
    "r",
    "t",
    "y",
    "u",
    "i",
    "o",
    "p",
    "a",
    "s",
    "d",
    "f",
    "g",
    "h",
    "j",
    "k",
    "l",
    "*",
    "z",
    "x",
    "c",
    "v",
    "b",
    "n",
    "m",
    "_",
    "@",
    "."
  };

static void	free_keyboard(void *data)
{
  Keyboard	*keyboard = data;

  free(keyboard->str);
  free(keyboard);
}

static Keyboard	*create_keyboard(char *str, size_t size, void (*ptr)(Keyboard *), void *data)
{
  Keyboard	*keyboard = safe_alloc(sizeof(Keyboard), free_keyboard);
  
  keyboard->str = malloc(size);
  if (str)
    strncpy(keyboard->str, str, size);
  keyboard->size = size;
  keyboard->data = data;
  keyboard->ptr = ptr;
  keyboard->state.x = 0;
  keyboard->state.y = 0;
  keyboard->state.layer = create_invert_layer(2, 18, 15, 15);
  return (keyboard);
}

static void	graphic(Layer *l, GContext *ctx)
{
  unsigned int	count = 0;
  Keyboard	*keyboard = get_window_data();

  putstr(keyboard->str, 0, 0, ctx);
  draw_line(0, 15, 144, 15, ctx);
  if (keyboard->state.y != 4)
    {
      invert_set_pos(keyboard->state.layer, 2 + keyboard->state.x * 14, 18 + keyboard->state.y * 23);
      invert_set_size(keyboard->state.layer, 15, 15);
    }
  else
    {
      invert_set_pos(keyboard->state.layer, 25 + (keyboard->state.x >= 5 ? 57 : 0), 120);
      invert_set_size(keyboard->state.layer, 42, 15);
    }
  while (count < SIZE(keys))
    {
      putstr(keys[count], 5 + (count % 10) * 14, 18 + ((count / 10) * 23), ctx);
      ++count;
    }
  putstr("Space", 30, 120, ctx);
  putstr("Enter", 90, 120, ctx);
}

static void	up()
{
  Keyboard	*keyboard = get_window_data();

  keyboard->state.x = (keyboard->state.x + (keyboard->state.y == 4 ? 5 : 1)) % 10;
  refresh();
}

static void	down()
{
  Keyboard	*keyboard = get_window_data();

  keyboard->state.y = (keyboard->state.y + 1) % 5;
  refresh();
}

static char	get_char(int x, int y)
{
  char		c;

  if (y == 4)
    c = (x >= 5 ? '<' : ' ');
  else
    c = (*keys[x + y * 10]);
  return (c);
}

static void	select()
{
  Keyboard	*keyboard = get_window_data();
  unsigned int	count = strlen(keyboard->str);
  char		c;

  if (keyboard->size)
    {
      c = get_char(keyboard->state.x, keyboard->state.y);
      if (c == '<')
	{
	  window_pop();
	  keyboard->size = strlen(keyboard->str);
	  keyboard->ptr(keyboard);
	  clean(keyboard);
	  return ;
	}
      if (count < keyboard->size - 1)
	{
	  keyboard->str[count] = c;
	  keyboard->str[count + 1] = 0;
	}
    }
  refresh();
}

static void	back()
{
  Keyboard	*keyboard = get_window_data();
  unsigned int	count = strlen(keyboard->str);

  if (keyboard->size && count < keyboard->size)
    keyboard->str[count - 1] = 0;
  refresh();

}

static void	click()
{
  window_single_click_subscribe(BUTTON_ID_UP, up);
  window_single_click_subscribe(BUTTON_ID_DOWN, down);
  window_single_click_subscribe(BUTTON_ID_SELECT, select);
  window_single_click_subscribe(BUTTON_ID_BACK, back);
}

void		create_basic_keyboard_scene_arg(char *str, size_t size, void (*ptr)(Keyboard *), void *data)
{
  Keyboard	*keyboard;

  create_basic_scene(graphic, NULL, NULL, click);
  keyboard = create_keyboard(str, size, ptr, data);
  set_window_data(keyboard);
}

void		create_basic_keyboard_scene(char *str, size_t size, void (*ptr)(Keyboard *))
{
  create_basic_keyboard_scene_arg(str, size, ptr, NULL);
}
