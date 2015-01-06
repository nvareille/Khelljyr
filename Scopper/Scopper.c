#include "Scopper.h"
#include <pebble.h>

void		*scopper(void *data, unsigned char ask)
{
  static void	*data_list[SCOPPER_ELEMENT_NBR];

  if (data)
    data_list[(int)ask] = data;
  return (data_list[(int)ask]);
}
