// Function to generate Pascal's triangle
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result array
    int** result = (int**)malloc(numRows * sizeof(int*));
    
    // Set the return size
    *returnSize = numRows;
    
    // Allocate memory for the return column sizes array
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    // Iterate over each row
    for (int i = 0; i < numRows; i++) {
        // Allocate memory for the current row
        result[i] = (int*)malloc((i+1) * sizeof(int));
        
        // Set the column size for the current row
        (*returnColumnSizes)[i] = i+1;
        
        // Set the first and last element of the current row to 1
        result[i][0] = 1;
        result[i][i] = 1;
        
        // Iterate over each element in the current row (excluding the first and last element)
        for (int j = 1; j < i; j++) {
            // Calculate the value of the current element by summing the two elements from the previous row
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    
    // Return the generated Pascal's triangle
    return result;
}