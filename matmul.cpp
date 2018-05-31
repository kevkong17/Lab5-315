#include <stdlib.h>
#include "matmul.h"

Matrix Allocate2ndMatrix(int height, int width, int init);

void matmul( float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

////////////////////////////////////////////////////////////////////////////////
//! C = A * B
//! @param C          result matrix
//! @param A          matrix A 
//! @param B          matrix B
//! @param hA         height of matrix A
//! @param wB         width of matrix B
////////////////////////////////////////////////////////////////////////////////

/* You'll need to modify this function such that matrix B is accessed
 * correctly once you change the memory layout to column-major. */
void matmul(float* C, const float* A, const float* B, unsigned int hA, 
    unsigned int wA, unsigned int wB)
{
  // Original 
  /*
  for (unsigned int i = 0; i < hA; ++i) {
    for (unsigned int j = 0; j < wB; ++j) {
      double sum = 0;
      for (unsigned int k = 0; k < wA; ++k) {
        double a = A[i * wA + k];
        double b = B[k * wB + j];
        sum += a * b;
      }
      C[i * wB + j] = (float)sum;
    }
  } 
  */

  
  //Column Major
  for (unsigned int i = 0; i < hA; ++i) {
    for (unsigned int j = 0; j < hA; ++j) {
      double sum = 0;
      for (unsigned int k = 0; k < wA; ++k) {
        double a = A[i * wA + k];
        double b = B[j * wB + k];
        sum += a * b;
      }
      C[i * wB + j] = (float)sum;
    }
  }
  

  // 16x16 Tile
  // Similar to above
  // Add two foor loops to limit across/down to 16
  // Make sure to index appropriately since we do not change i or j until we finish the tile
  /*
   for (unsigned int i = 0; i < hA; i += 16 ) {
      for (unsigned int j = 0; j < hA; j += 16 ) {
         for(int k = 0; k < 16; ++k) {
            for(int l = 0; l < 16; ++l) {
              double sum = 0;
              for (unsigned int m = 0; m < wA; ++m) {
                double a = A[(i+k) * wA + m];
                double b = B[(j+l) * wA + m];
                sum += a*b;
              }
              C[(i+k) * wB + (j+l)] = (float)sum;
            }
         }
      }
   }

   // 32x32 Tile
   // Same as 16x16 but with 32 instead of 16
   
   for (unsigned int i = 0; i < hA; i += 32 ) {
      for (unsigned int j = 0; j < hA; j += 32 ) {
         for(int k = 0; k < 32; ++k) {
            for(int l = 0; l < 32; ++l) {
              double sum = 0;
              for (unsigned int m = 0; m < wA; ++m) {
                double a = A[(i+k) * wA + m];
                double b = B[(j+l) * wA + m];
                sum += a*b;
              }
              C[(i+k) * wB + (j+l)] = (float)sum;
            }
         }
      }
   }
   */

} 

// Allocate a matrix of dimensions height*width
Matrix Allocate2ndMatrix(int height, int width)
{
  Matrix M;
  M.width = M.pitch = width;
  M.height = height;
  int size = M.width * M.height;
  M.elements = NULL;

  M.elements = (float*) malloc(size*sizeof(float));

  /* This is a row-major allocation and initialization.
   * You need to modify this function which is only called
   * for Matrix B such that a column-major ordering is
   * performed. */
  
  /* Original 
  for(unsigned int i = 0; i < M.height * M.width; i++)
  {
    M.elements[i] = (rand() / (float)RAND_MAX);
  }
  return M;
  */
  
  //Generate entire column and then move to next column 
  for(unsigned int i = 0; i < M.height; i++){
    for(unsigned int j = 0; j < M.width; j++){
      M.elements[i+j * M.width] = (rand() / (float)RAND_MAX);
    }
  }
  return M;
}	

