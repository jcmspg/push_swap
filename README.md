# Key Concept: Two Stack Sorting

### The basic idea remains to:

    Divide the numbers into blocks.
    Sort and move the blocks between the two stacks (a and b).
    Gradually build a sorted sequence in Stack A by carefully placing elements back from Stack B.

### Here’s how you can use your movements with Block Sort.

![steps](assets/napkin-selectiom.png "napkin scheme 1")


## Step 1: Divide into Blocks

    Split your numbers into chunks (blocks), based on the total size of the stack. For example, if you have 100 numbers, you can divide them into blocks of 20.
    These blocks should be organized by value (e.g., block 1 contains the smallest 20 numbers, block 2 the next 20, etc.).
    Push elements from A to B in chunks using pb.

### Example:

    Find the smallest 20 numbers in A (block 1).

    Use pb to push each number to Stack B until the first block is transferred.

    Useful commands here:
        pb to push from A to B.
        You can use ra or rra to rotate Stack A to find the correct element efficiently, rather than cycling through the whole stack.

## Step 2: Sorting Blocks in Stack B

Now that you've moved a block to Stack B, you need to sort it in B before pushing it back to Stack A.

    Once the block is in B, sort it using the available operations.
    Insertion Sort works well with this, as you can sort incrementally while elements are pushed into B:
        After each pb, check if you need to adjust the order in B using rb or rrb.
    Useful commands:
        sb to swap the top two elements if needed.
        rb and rrb to rotate Stack B to bring elements into the correct order.

## Step 3: Push Sorted Blocks Back to Stack A

Once a block is sorted in B, you push the elements back to Stack A.

    Use the pa operation to push elements back to A, ensuring you maintain sorted order in A.
    Use rotations (ra/rra) to insert elements at the correct position in Stack A.

### Example:

    After sorting block 1 in B, push it back to A using pa until Stack A has the smallest 20 numbers in order.

    Useful commands:
        pa to move from B to A.
        ra or rra to adjust the position in Stack A.

## Step 4: Repeat for Each Block

Continue this process for all the blocks:

    Push the next block to Stack B.
    Sort it.
    Push it back to Stack A in the correct order.

## Optimizations to Reduce Movements

### To minimize movements, you need to optimize how you rotate and push elements:

    Smart Rotations: When pushing blocks to Stack B, use ra/rra efficiently to avoid unnecessary operations. If the next element you want to push is closer to the top or bottom, use the corresponding rotate operation (ra or rra) to minimize movement.
    Merge Back Efficiently: When you are merging sorted blocks back into Stack A, make sure you are placing elements in the correct order by rotating A as needed, so you don’t need extra operations later.

## Why This Approach Works

    By dividing the array into manageable blocks, you can work within the constraints of limited operations, processing smaller chunks of data at a time.
    Sorting within Stack B helps you avoid having to perform unnecessary swaps in Stack A, and ensures that each block returns to A sorted, leading to an overall sorted array.
    You avoid the high number of swaps or unnecessary back-and-forth movements by sorting in smaller blocks.

## Additional Considerations

    Block Size: Experiment with different block sizes (e.g., √n for large inputs, or even smaller blocks for minimal swaps).
    Edge Cases: Handle small input sizes by directly sorting them using sa, sb, pa, and pb without block division if sorting a few elements.

## Example Plan

Suppose you have an array of 100 numbers:

1.   Divide the array into blocks of 20 numbers each.
2.   Push the first block of 20 smallest numbers to Stack B using pb, sorting it in B as you push elements.
3.    Push the sorted block back to Stack A using pa.
4.    Repeat this process for all remaining blocks until the array is sorted.
