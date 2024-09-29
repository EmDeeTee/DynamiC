```c
  #include <DynamiC.h>

  DynamiCArray arr = DynamiCMakeArray(sizeof(int));
  for (size_t i = 0; i <= 10; i++) {
    DynamiCAppendToArray(&arr, &i);
  }
  DynamiCForEach(int, element, arr) {
    printf("Element: %d\n", *element);
  }
```
