NQUEENS(k)
{
    // Try placing the queen in each column of row k
    for (col = 1 to 5)
    {
        // Check whether placing the queen at (k, col) is safe
        if (SAFE(k, col))
        {
            x[k] = col;    // Place the queen in column col of row k

            // If all 5 queens have been placed, print the solution
            if (k == 5)
                print x[1..5];

            // Otherwise, recursively place a queen in the next row
            else
                NQUEENS(k + 1);
        }
    }
}


SAFE(k, col)
{
    // Check the new queen against all previously placed queens
    for (i = 1 to k - 1)
    {
        // Check whether two queens are in the same column
        // OR on the same diagonal
        if (x[i] == col ||
            abs(x[i] - col) == abs(i - k))
            return false;  // Queen placement is not safe
    }

    // No previous queen attacks the current position
    return true;
}