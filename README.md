# Push_Swap
This project aims to solidify one's knowledge about algorithms, efficiency and complexity.
The requirements for this project is to sort numbers given to us without duplicates using as little commands as possible, sounds confusing right? let's hop into it!

## Rules

- You have 2 stacks named a and b.

- At the beginning:
    -- The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
    -- The stack b is empty.

- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
    -- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

    -- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

    -- ss : sa and sb at the same time.

    -- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

    -- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

    -- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

    -- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

    -- rr : ra and rb at the same time.

    -- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

    -- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

    -- rrr : rra and rrb at the same time.

## Contents

After some research I came to the conclusion that none of the traditional sorting algorithms could be modified or implemented in order to solve this problem, none except one: The Radix Sort.

The Radix Sort is a variant of the bucket sorting algorithm which uses multiple buckets, one for each digit in our numbers and then proceeds to sort them.

However the radix sort like mentionned above requires as many "buckets" as the biggest number we have has digits, and as presented earlier we only are allowed to use two "buckets" or stacks if you may, additionaly, the radix sort does not work with negative numbers!

In order to tackle this issue, I had to modify the radix sort in such a way that only two buckets were needed and negative numbers could be handled and this is how:

- First we need to create a new set of numbers to sort, the idea here is to map out our numbers into other numbers, which means that the list of operations we will produce to sort our new numbers will also sort our initial numbers, this allows us to essentially remove negative numbers since all the numbers present will be mapped onto positive numbers, this will fix our first problem of the radix sort not being able to handle negative numbers.

- Secondly, the radix sort relies on digit sorting, and we require a bucket for each digit we have, this issue can be completely removed if we use bit shifting. In fact all we would have to do is simply use two nested loops, convert the number in binary at which point we would only need two buckets which is the exact same problem as push_swap!

- Implementing the solutions mentionned above changes the Radix sort in a way that would allow it to be used for our current problem and it produced acceptable results for the school's standards, it is however worth mentionning that regular space and time complexity are not ideal, however the measure for complexity in this project lies within the number of operations needed to perform the sort.

## Usage

You will need to generate numbers without duplicates and pass them either as a single argument or multiple arguments and then run the executable with those arguments, the output will be a list of commands that will effectively sort the stack!

Using this website you can visualize the sorting process to have a better understanding of how it works : https://codepen.io/ahkoh/pen/bGWxmVz
