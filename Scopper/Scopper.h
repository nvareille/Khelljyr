#ifndef SCOPPER_H_
# define SCOPPER_H_

# define SCOPPER_ELEMENT_NBR 4

/**
 * This function saves and returns some critical data for the framework. If you want to get data from it, it is more convenient to use the macros like USER_PTR instead.
 * @param data if not null, will put data into memory. If null, will return the stored data.
 * @param id The identifier of the data to get.
 * @return The stored value of id.
 */
void	*scopper(void *data, unsigned char id);

#endif
