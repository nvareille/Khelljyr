Khelljyr 0.12
![alt tag](https://github.com/nvareille/Khelljyr/blob/master/Logo.png)
========

A powerful pebble framework that abstracts layers, windows and implement several features like garbage collector.
Check the examples here: https://github.com/nvareille/KhelljyrExamples

What's implemented ?

- BasicScene

  Calling the function create_basic_scene() will create a new window ready to be used and without taking care of it !
  just set the two handlers and the update function and everything is fine ! (window_stack_pop() will free it and free what's has been allocated on it)

  Calling the function create_basic_scene_fullscreen() will create it in fullscreen

  It is possible too to set a click provider directly

- BasicMenuScene

  Possibility to create a pebble menu in just one line of code with create_basic_menu_scene() !

- BasicTextScene

  Possibility to create a Scrolling text in just one line of code with create_basic_text_scene() !

- Keyboard

  Create a Keyboard screen just by using one function !

- InvertLayer

  An abstraction of the Inverted Layer. Very easy to use, move and change the size.

- MemoryManager:
  
  When you allocate memory with Khelljyr (alloc(), custom_alloc()) or you have memory that must be handled (resource_handle()),
  everything will be cleared when the window is destroyed. Forget about memory leaks with this feature !

- MessageManager:

  A powerfull message abstraction. It is very easy to create a message and send it to the phone. It handles success and failures

- Img:

  A nice abstractions to GBitmap pictures. Very easy to use and handled by the MemoryManager, once loaded with create_img() it's ready for use !

- Useful Macros

  USER_PTR will be a pointer to your user data that you pass to app_init().
  MEMORYMANAGER_PTR and GRAPHIC_PTR will return pointers to structures of the framework (without calling the fuctions and accessible everywhere in the code !)

- Debug:

  Two functions are available (DUMP and PRINT). DUMP() will allow you to log with format, PRINT will just log some text.

- Utils functions

  putstr() will write some text in a graphic context very easily
  putstr_font() will write some text with custom font
  putstr_format() will write some text with format
  draw_line() will trace a line on the pebble screen

- Timers:
  
  Some useful timers that repeat themselves and are easy to handle.

- Containers

  Lists and Stacks that can be iterated with the foreach function