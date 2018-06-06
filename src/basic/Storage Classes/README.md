
## What is a Storage Class ?

Storage class in C decides the part of storage to allocate memory for a variable, it also determines the scope of a variable. All variables defined in a C program get some physical location in memory where variable's value is stored. Memory and CPU registers are types of memory locations where a variable's value can be stored. The storage class of a variable in C determines the life time of the variable if this is 'global' and 'local'. Along with the life time of a variable, storage class also determines variable's storage location (memory or registers), the scope (visibility level) of the variable, and the initial value of the variable. There are four storage classes in C those are **automatic**, **register**, **static**, **external**.

## Storage Class Specifiers

There are four storage class specifiers in C as follows, **typedef** specifier does not reserve storage and is called a storage class specifier only for syntactic convenience. It is not a storage class sepcifier in the common meaning.

- auto
- register
- extern
- static

These specifiers tell the compiler how to store the subsequent variable. The general form of a variable declaration that uses a storage class is shown here:

```
storage_class_specifier     data_type    variable_name;
```

## Types of Storage Classes

There are four storage classes in C they are as follows:

1. Automatic Storage Class
2. Register Storage Class
3. Static Storage Class
4. External Storage Class


## References

- http://cs-fundamentals.com/c-programming/storage-classes-in-c-and-storage-class-specifiers.php
- https://www.geeksforgeeks.org/storage-classes-in-c/