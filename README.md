Khelljyr 0.1
========

A powerful pebble framework that abstracts layers, windows and implement several features like garbage collector.

What's implemented ?

- SimpleScene

  Calling the function create_basic_scene() will create a new window ready to be used and without taking care of it !
  just set the two handlers and the update function and everything is fine ! (window_stack_pop() will free it and free what's has been allocated on it)

- MemoryManager:
  
  When you allocate memory with Khelljyr (alloc(), custom_alloc()) or you have memory that must be handled (ressource_handle()),
  everything will be cleared when the window is destroyed. Forget about memory leaks with this feature !

- Useful Macros

  MEMORYMANAGER_PTR and GRAPHIC_PTR will return pointers to structures of the framework (without calling the fuctions and accessible everywhere in the code !)

- Debug:

  Two functions are available (DUMP and PRINT). DUMP() will allow you to log with format, PRINT will just log some text.

- Utils functions

  putstr() will write some text in a graphic context very easily