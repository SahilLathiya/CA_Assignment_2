#include <stdio.h>

__global__ void convolutionKernel(int input_row,
                                  int input_col,
                                  int *input,
                                  int kernel_row,
                                  int kernel_col,
                                  int *kernel,
                                  int output_row,
                                  int output_col,
                                  long long unsigned int *output, int N) {

	int index = blockIdx.x*blockDim.x + threadIdx.x;
	if(index >= N)
        return;
	int output_i = index / output_col;
        int output_j = index % output_col;
        long long unsigned int res = 0;
	for(int kernel_i = 0; kernel_i< kernel_row; kernel_i++) {
		for(int kernel_j = 0; kernel_j< kernel_col; kernel_j++) {
		    int input_i = (output_i + 2*kernel_i) % input_row;
		    int input_j = (output_j + 2*kernel_j) % input_col;
		    res += input[input_i*input_col +input_j] * kernel[kernel_i*kernel_col +kernel_j];
		}
        output[index] = res;
	}
}
// Fill in this function
void gpuThread( int input_row, 
                int input_col,
                int *input, 
                int kernel_row, 
                int kernel_col, 
                int *kernel,
                int output_row, 
                int output_col, 
                long long unsigned int *output ) 
{
    // Allocate device memory
    int *d_input, *d_kernel;
    long long unsigned int *d_output;
    cudaMalloc((void **)&d_input, input_row * input_col * sizeof(int));
    cudaMalloc((void **)&d_kernel, kernel_row * kernel_col * sizeof(int));
    cudaMalloc((void **)&d_output, output_row * output_col * sizeof(long long unsigned int));

    // Copy input and kernel to device memory
    cudaMemcpy(d_input, input, input_row * input_col * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_kernel, kernel, kernel_row * kernel_col * sizeof(int), cudaMemcpyHostToDevice);

    // Set grid and block dimensions
    // dim3 blockDim(8, 8);
    // dim3 gridDim((output_row + blockDim.x - 1) / blockDim.x, (output_col + blockDim.y - 1) / blockDim.y);

    int N = output_row*output_col;
    int NUM_THREAD = 512;
    int NUM_BLOCK = (N + NUM_THREAD - 1)/NUM_THREAD;
    
    // Launch kernel
    convolutionKernel<<<NUM_BLOCK, NUM_THREAD>>>(input_row, input_col, d_input, kernel_row, kernel_col, d_kernel,
                                             output_row, output_col, d_output,N);

    // Copy the result back to the host
    cudaMemcpy(output, d_output, output_row * output_col * sizeof(long long unsigned int), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_kernel);
    cudaFree(d_output);
}
