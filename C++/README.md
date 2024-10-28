# C++ Data Types Overview

This README provides an overview of the different data types in C++, including floating-point types such as `long double`, as well as other numeric and character types.

## Floating-Point Types

C++ provides three main floating-point types to store decimal values:

1. **`float`**: Single-precision floating-point number.
   - Precision: ~6-7 decimal digits.
   - Size: 4 bytes.
   - Example:
     ```cpp
     float pi = 3.14f;
     ```

2. **`double`**: Double-precision floating-point number.
   - Precision: ~15 decimal digits.
   - Size: 8 bytes.
   - Example:
     ```cpp
     double e = 2.71828;
     ```

3. **`long double`**: Extended-precision floating-point number.
   - Precision: More than `double` (platform-dependent).
   - Size: 10, 12, or 16 bytes (platform-dependent).
   - Example:
     ```cpp
     long double largeNum = 120.452L;
     ```

## Integer Types

Integer types are used to store whole numbers:

1. **`int`**: Standard integer.
   - Size: 4 bytes.
   - Example:
     ```cpp
     int age = 25;
     ```

2. **`long`**: Larger integer type.
   - Size: At least 4 bytes.
   - Example:
     ```cpp
     long distance = 100000L;
     ```

3. **`long long`**: Even larger integer.
   - Size: 8 bytes.
   - Example:
     ```cpp
     long long bigNum = 123456789LL;
     ```

4. **`short`**: Shorter integer type.
   - Size: 2 bytes.
   - Example:
     ```cpp
     short smallNum = 100;
     ```

5. **`unsigned int`, `unsigned long`, `unsigned long long`**: Used for non-negative integers.
   - Example:
     ```cpp
     unsigned int positiveNum = 50U;
     ```

## Fixed-width Integer Types

These types offer guaranteed sizes and are available through `<cstdint>`:

1. **`int32_t`**: 32-bit signed integer.
   - Example:
     ```cpp
     int32_t num = 42;
     ```

2. **`uint64_t`**: 64-bit unsigned integer.
   - Example:
     ```cpp
     uint64_t largeNum = 1000000ULL;
     ```

## Boolean Type

1. **`bool`**: Represents `true` or `false`.
   - Size: 1 byte.
   - Example:
     ```cpp
     bool isEven = true;
     ```

## Character Types

1. **`char`**: Stores a single character.
   - Size: 1 byte.
   - Example:
     ```cpp
     char letter = 'A';
     ```

2. **`wchar_t`, `char16_t`, `char32_t`**: Used for wide or Unicode characters.
   - Example:
     ```cpp
     wchar_t wideChar = L'B';
     ```

## Notes

- The size and precision of `long double` and other types may vary depending on the platform.
- Use `<cstdint>` for precise-width integers to ensure portability.

## License

This guide is free to use and modify under the MIT License.
