// Optimize this function
void singleThread( int input_row, 
                int input_col,
                int *input, 
                int kernel_row, 
                int kernel_col, 
                int *kernel,
                int output_row, 
                int output_col, 
                long long unsigned int *output ) 
{
    // Given Code
    for(int i = 0; i < output_row * output_col; ++i)
        output[i] = 0;

    for(int output_i = 0; output_i < output_row; output_i++)
    {
        int outi_into_outcol = output_i * output_col;

        for(int output_j = 0; output_j < output_col; output_j+=4)
        {
            int out_0 = outi_into_outcol + output_j;
            long long unsigned int ans_0 = 0;
            long long unsigned int ans_1 = 0;
            long long unsigned int ans_2 = 0;
            long long unsigned int ans_3 = 0;

            if(output_j + 3 < output_col){
            
                for(int kernel_i = 0; kernel_i< kernel_row; kernel_i++)
                {
                    int input_i = (output_i + (kernel_i<<1)) % input_row;
                    int keri_into_kercol = kernel_i*kernel_col;
                    int inpi_into_inpcol = input_i*input_col;

                    for(int kernel_j = 0; kernel_j < kernel_col; kernel_j+=4)
                    {
                        
                        int k1 = keri_into_kercol + kernel_j;
                        
                        if(kernel_j + 3 < kernel_col){
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;
                            int input_j_2 = (output_j + ((kernel_j+2)<<1)) % input_col;
                            int input_j_3 = (output_j + ((kernel_j+3)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1]+
                            input[inpi_into_inpcol + input_j_2] * kernel[k1+2]+
                            input[inpi_into_inpcol + input_j_3] * kernel[k1+3];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 1) % input_col] * kernel[k1+2]+
                            input[inpi_into_inpcol + (input_j_3 + 1) % input_col] * kernel[k1+3];

                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 2) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 2) % input_col] * kernel[k1+2]+
                            input[inpi_into_inpcol + (input_j_3 + 2) % input_col] * kernel[k1+3];

                            ans_3 += input[inpi_into_inpcol + (input_j + 3) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 3) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 3) % input_col] * kernel[k1+2]+
                            input[inpi_into_inpcol + (input_j_3 + 3) % input_col] * kernel[k1+3];

                        }
                        else if(kernel_j + 2 < kernel_col){
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;
                            int input_j_2 = (output_j + ((kernel_j+2)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1]+
                            input[inpi_into_inpcol + input_j_2] * kernel[k1+2];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 1) % input_col] * kernel[k1+2];

                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 2) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 2) % input_col] * kernel[k1+2];

                            ans_3 += input[inpi_into_inpcol + (input_j + 3) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 3) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 3) % input_col] * kernel[k1+2];
                            

                        }
                        else if(kernel_j + 1 < kernel_col){

                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1];

                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 2) % input_col] * kernel[k1+1];

                            ans_3 += input[inpi_into_inpcol + (input_j + 3) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 3) % input_col] * kernel[k1+1];

                        }
                        else{
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1];
                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1];
                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1];
                            ans_3 += input[inpi_into_inpcol + (input_j + 3) % input_col] * kernel[k1];
                        }
                    }
                    output[out_0] = ans_0;
                    output[out_0 + 1] = ans_1;
                    output[out_0 + 2] = ans_2;
                    output[out_0 + 3] = ans_3;
 
                }
            }
            else if(output_j + 2 < output_col){
                for(int kernel_i = 0; kernel_i< kernel_row; kernel_i++)
                {
                    int input_i = (output_i + (kernel_i<<1)) % input_row;
                    int keri_into_kercol = kernel_i*kernel_col;
                    int inpi_into_inpcol = input_i*input_col;

                    for(int kernel_j = 0; kernel_j < kernel_col; kernel_j+=4)
                    {
                        
                        int k1 = keri_into_kercol + kernel_j;
                        
                        if(kernel_j + 3 < kernel_col){
                            
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;
                            int input_j_2 = (output_j + ((kernel_j+2)<<1)) % input_col;
                            int input_j_3 = (output_j + ((kernel_j+3)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1]+
                            input[inpi_into_inpcol + input_j_2] * kernel[k1+2]+
                            input[inpi_into_inpcol + input_j_3] * kernel[k1+3];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 1) % input_col] * kernel[k1+2]+
                            input[inpi_into_inpcol + (input_j_3 + 1) % input_col] * kernel[k1+3];

                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 2) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 2) % input_col] * kernel[k1+2]+
                            input[inpi_into_inpcol + (input_j_3 + 2) % input_col] * kernel[k1+3];

                        }
                        else if(kernel_j + 2 < kernel_col){
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;
                            int input_j_2 = (output_j + ((kernel_j+2)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1]+
                            input[inpi_into_inpcol + input_j_2] * kernel[k1+2];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 1) % input_col] * kernel[k1+2];

                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 2) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 2) % input_col] * kernel[k1+2];

                        }
                        else if(kernel_j + 1 < kernel_col){

                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1];

                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 2) % input_col] * kernel[k1+1];

                        }
                        else{
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1];
                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1];
                            ans_2 += input[inpi_into_inpcol + (input_j + 2) % input_col] * kernel[k1];
                        }
                    }
                    output[out_0] = ans_0;
                    output[out_0 + 1] = ans_1;
                    output[out_0 + 2] = ans_2;
 
                }
            }
            else if(output_j + 1 < output_col){

                for(int kernel_i = 0; kernel_i< kernel_row; kernel_i++)
                {
                    int input_i = (output_i + (kernel_i<<1)) % input_row;
                    int keri_into_kercol = kernel_i*kernel_col;
                    int inpi_into_inpcol = input_i*input_col;

                    for(int kernel_j = 0; kernel_j < kernel_col; kernel_j+=4)
                    {
                        
                        int k1 = keri_into_kercol + kernel_j;
                        
                        if(kernel_j + 3 < kernel_col){
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;
                            int input_j_2 = (output_j + ((kernel_j+2)<<1)) % input_col;
                            int input_j_3 = (output_j + ((kernel_j+3)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1]+
                            input[inpi_into_inpcol + input_j_2] * kernel[k1+2]+
                            input[inpi_into_inpcol + input_j_3] * kernel[k1+3];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 1) % input_col] * kernel[k1+2]+
                            input[inpi_into_inpcol + (input_j_3 + 1) % input_col] * kernel[k1+3];

                        }
                        else if(kernel_j + 2 < kernel_col){
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;
                            int input_j_2 = (output_j + ((kernel_j+2)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1]+
                            input[inpi_into_inpcol + input_j_2] * kernel[k1+2];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (input_j_2 + 1) % input_col] * kernel[k1+2];

                        }
                        else if(kernel_j + 1 < kernel_col){

                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            int input_j_1 = (output_j + ((kernel_j+1)<<1)) % input_col;

                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1]+
                            input[inpi_into_inpcol + input_j_1] * kernel[k1+1];

                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (input_j_1 + 1) % input_col] * kernel[k1+1];

                        }
                        else{
                            int input_j = (output_j + (kernel_j<<1)) % input_col;
                            ans_0 += input[inpi_into_inpcol + input_j] * kernel[k1];
                            ans_1 += input[inpi_into_inpcol + (input_j + 1) % input_col] * kernel[k1];
                        }
                    }
                    output[out_0] = ans_0;
                    output[out_0 + 1] = ans_1;
 
                }
            }
            else{
                for(int kernel_i = 0; kernel_i< kernel_row; kernel_i++)
                {
                    int input_i = (output_i + (kernel_i<<1)) % input_row;
                    int keri_into_kercol = kernel_i*kernel_col;
                    int inpi_into_inpcol = input_i*input_col;

                    for(int kernel_j = 0; kernel_j< kernel_col; kernel_j+=4)
                    {
                        int k1 = keri_into_kercol +kernel_j;
                        if(kernel_j + 3 < kernel_col){
                            
                            ans_0 += input[inpi_into_inpcol + (output_j + (kernel_j<<1)) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (output_j + ((kernel_j+1)<<1)) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (output_j + ((kernel_j+2)<<1)) % input_col] * kernel[k1+2]+
                            input[inpi_into_inpcol + (output_j + ((kernel_j+3)<<1)) % input_col] * kernel[k1+3];
                        }
                        else if(kernel_j + 2 < kernel_col){
                            
                            ans_0 += input[inpi_into_inpcol + (output_j + (kernel_j<<1)) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (output_j + ((kernel_j+1)<<1)) % input_col] * kernel[k1+1]+
                            input[inpi_into_inpcol + (output_j + ((kernel_j+2)<<1)) % input_col] * kernel[k1+2];

                        }
                        else if(kernel_j + 1 < kernel_col){
                            
                            ans_0 += input[inpi_into_inpcol + (output_j + (kernel_j<<1)) % input_col] * kernel[k1]+
                            input[inpi_into_inpcol + (output_j + ((kernel_j+1)<<1)) % input_col] * kernel[k1+1];

                        }else{
                            
                            ans_0 += input[inpi_into_inpcol + (output_j + (kernel_j<<1)) % input_col] * kernel[k1];
                        }
                    }
                    output[out_0] = ans_0;
                }

            }
        }
    }
}