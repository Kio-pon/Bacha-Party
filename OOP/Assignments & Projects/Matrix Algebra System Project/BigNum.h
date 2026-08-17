#ifndef BIG_NUM_H
#define BIG_NUM_H

#include <string>

/**
 * @class BigNum
 * @brief Represents arbitrarily large integers using dynamic storage.
 *
 * Provides constructors, arithmetic operations, input/output handling,
 * and comparison operators for very large numbers that exceed the limits
 * of built-in integer types.
 */
class BigNum {
public:

    /**
     * @brief Default constructor. Initializes the number to "0".
     */
    BigNum();

    /**
     * @brief Copy constructor.
     * @param bigNum The BigNum instance to copy.
     */
    BigNum(const BigNum& bigNum);

    /**
     * @brief Constructs a BigNum from a string.
     * @param bigStr A string containing digits (e.g., "348723482").
     */
    BigNum(const std::string& bigStr);

    /**
     * @brief Constructs a BigNum from an integer.
     * @param num An integer value (e.g., 487234985).
     */
    BigNum(const int num);

    /**
     * @brief Destructor. Frees any dynamically allocated memory.
     */
    ~BigNum();

    // ===== Input/Output Operations =====

    /**
     * @brief Reads a number from standard input.
     *
     * Clears the current value before reading.
     * Uses clear() internally.
     */
    void input();

    /**
     * @brief Prints the number to standard output.
     *
     * Formats the output with commas after every 3 digits
     * (e.g., 12,345,678).
     */
    void print();

    /**
     * @brief Reads a number from a file.
     * @param fileName Name of the file to read from.
     *
     * Clears the current value before reading.
     * Uses clear() internally.
     */
    void inputFromFile(const std::string& fileName);

    /**
     * @brief Writes the number to a file.
     * @param fileName Name of the file to write to.
     */
    void printToFile(const std::string& fileName);

    // ===== Initialization/Assignment Operations =====

    /**
     * @brief Copies the value from another BigNum.
     * @param bigNum The source BigNum.
     */
    void copy(const BigNum& bigNum);

    /**
     * @brief Assignment operator overload.
     * @param bigNum The source BigNum.
     */
    void operator=(const BigNum& bigNum);

    /**
     * @brief Resets the number to "0".
     */
    void zerofy();

    // ===== Arithmetic Operations: Addition =====

    /**
     * @brief Increments the number by 1.
     */
    void increment();

    /**
     * @brief Adds another BigNum to this BigNum.
     * @param bigNum The BigNum to add.
     * @return A new BigNum containing the sum.
     */
    BigNum add(const BigNum& bigNum);

    /**
     * @brief Adds an integer to this BigNum.
     * @param num Integer to add.
     * @return A new BigNum containing the sum.
     */
    BigNum add(const int num);

    /**
     * @brief Adds another BigNum to this BigNum in-place.
     * @param bigNum The BigNum to add.
     */
    void compoundAdd(const BigNum& bigNum);

    /**
     * @brief Adds an integer to this BigNum in-place.
     * @param num Integer to add.
     */
    void compoundAdd(const int num);

    // ===== Arithmetic Operations: Subtraction =====

    /**
     * @brief Decrements the number by 1.
     */
    void decrement();

    /**
     * @brief Subtracts another BigNum from this BigNum.
     * @param bigNum The BigNum to subtract.
     * @return A new BigNum containing the difference.
     */
    BigNum subtract(const BigNum& bigNum);

    /**
     * @brief Subtracts an integer from this BigNum.
     * @param num Integer to subtract.
     * @return A new BigNum containing the difference.
     */
    BigNum subtract(const int num);

    /**
     * @brief Subtracts another BigNum from this BigNum in-place.
     * @param bigNum The BigNum to subtract.
     */
    void compoundSubtract(const BigNum& bigNum);

    /**
     * @brief Subtracts an integer from this BigNum in-place.
     * @param num Integer to subtract.
     */
    void compoundSubtract(const int num);

    // ===== Arithmetic Operations: Multiplication and Division =====

    /**
     * @brief Multiplies this BigNum by another BigNum.
     * @param bigNum The BigNum multiplier.
     * @return A new BigNum containing the product.
     */
    BigNum multiply(const BigNum& bigNum);

    /**
     * @brief Performs integer division of this BigNum by another BigNum.
     * @param bigNum The divisor.
     * @return A new BigNum containing the quotient.
     */
    BigNum div(const BigNum& bigNum);

    /**
     * @brief Computes the remainder when this BigNum is divided by another
     * BigNum.
     * @param bigNum The divisor.
     * @return A new BigNum containing the remainder.
     */
    BigNum mod(const BigNum& bigNum);

    // ===== Comparison Operations =====

    /**
     * @brief Checks if two BigNums are equal.
     * @param bigNum The BigNum to compare.
     * @return True if equal, otherwise false.
     */
    bool equals(const BigNum& bigNum);

    /**
     * @brief Checks if two BigNums are not equal.
     * @param bigNum The BigNum to compare.
     * @return True if not equal, otherwise false.
     */
    bool notEquals(const BigNum& bigNum);

    /**
     * @brief Checks if this BigNum is less than another.
     * @param bigNum The BigNum to compare.
     * @return True if less than, otherwise false.
     */
    bool lessThan(const BigNum& bigNum);

    /**
     * @brief Checks if this BigNum is greater than another.
     * @param bigNum The BigNum to compare.
     * @return True if greater than, otherwise false.
     */
    bool greaterThan(const BigNum& bigNum);

private:

    // Internal representation of the number:
    // (e.g., vector<char>, dynamically allocated char*, or linked list).
    // No static arrays are allowed.

    /**
     * @brief Clears the current stored number.
     *
     * Equivalent to deleting the dynamic array or releasing memory.
     * Called in destructor and input methods before resetting the value.
     */
    void clear();
};

#endif
