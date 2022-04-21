# POSTNET
### Background
From 1965-2013,the US Postal Service used a bar code on every envelope representing
the zip code (The zip code was introduced in 1963) using a format called POSTNET. A
bar code is still used, but POSTNET was retired completely in 2013. We will be
implementing POSTNET as a class for 5-digit zip codes.

POSTNET consists of long and short lines or bars, as seen below:

![The POSTNET representation of 67260, WSU's zip code](img/67260.png)

The image represents the zip code 67260, which you might recognize as WSU's zip
code. We can think of the long bars as '1' and the short bars as '0'. A POSTNET
code consists of 32 bars/digits (They will be referred to as digits from now on).
The first and last digit are always '1'. Stripping these leaves 30 digits, which
can be split into groups of 5.

<p align="center">
    <code>10110010001001010110011000101001</code><br>
    <code>*01100* 10001 00101 01100 11000 10100</code>
</p>

Now, we look at the first five groups of five. There will always be two 1s.
Each 1 represents a number based on its location in the group. Summing those
numbers represented by the 1s provides a single digit of the zip code. The table
below translates the group marked with \*\*, which represents the number 6.

<table align="center">
    <tr>
        <th align="left">POSTNET Digits</th>
        <td>0</td>
        <td>1</td>
        <td>1</td>
        <td>0</td>
        <td>0</td>
    </tr>
    <tr>
        <th align="left">Value</th>
        <td>7</td>
        <td>4</td>
        <td>2</td>
        <td>1</td>
        <td>0</td>
    </tr>
</table>

We see that the 1s correspond to the values of 4 and 2. Adding them up gives us
6, which is the first digit of the zip code (and also the fourth since the same
group appears again, due to the zip code having two 6s).

In order to represent the number 0, the 1s must add up to a value of 11. This
is done because of the requirement that every group of five must have two 1s.

The sixth group is known as the "check digit". This is included so that sorting
machines can catch reading errors. The check digit is calculated by summing the
5 digits of the zip code and adding the check digit such that the total sum is
a multiple of 10. In the example above:

<p align="center">
6 + 7 + 2 + 6 + 0 = 21<br>
10 - (21 % 10) = 9
</p>

The check digit for the zip code 67260 is 9, meaning all six digits sum to 30,
which is a multiple of 10. If the sum of the 5 zip code digits is already a
multiple of 10, the check digit is 0.

## Requirements
- The only code file you will modify is `Zipcode.hpp`.
    - Remember to fill out the top comment.
- The file `Zipcode.hpp` contains a class declaration. You must write the
implementations in this file.
- You may declare and use additional functions if needed.
- You may assume that any 5-digit number is a valid zip code.

## Sample Run
For this assignment, an actual testing framework, doctest, will be used to
compile and run tests on  your code. You may view `main.cpp` to see the
tests.
```
[doctest] doctest version is "2.4.1"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases:  8 |  8 passed | 0 failed | 0 skipped
[doctest] assertions: 15 | 15 passed | 0 failed |
[doctest] Status: SUCCESS!
```

## Hints
- Ignore the contents of `doctest.h`, it is the testing framework; there is no
information in it that will aid in the completion of the assignment.
    - Naturally, if you find yourself with the time it might be worth checking
    out the repository at
    [https://github.com/onqtam/doctest](https://github.com/onqtam/doctest)
- You do not need to write the entire class before testing.
    - You can either stub functions you have not yet written, or comment out
    those tests.
- Look at the tests to know what is expected of the class.
    - Corollary: The comments in `Zipcode.h` are also there to help you.
- The testing framework provides many options that you can pass to the program.
Two examples:
    - `-s    Shows verbose output for successful tests`
    - `-nc   Will not print using color`
- The required functions must be implemented, but there is nothing stopping you
from adding private helper functions and data to the class.
    - As an example, my implementation contains one other data member and four
    private functions on top of what's required.

## Reminders
- Name your file *wsuid*\"_hw09.cpp
- You are required to place a comment block at the top of the file. Refer to the Coding Guidelines
handout.
