#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <threads.h>
#include <complex.h>
#include <time.h>
#include <math.h>

int threads = 0;
int size = 0;
int degree_global = 0;
double epsilon=1e-3;
double epsilon2=1e-6;
long int upper_limit=10000000000;
complex double roots[10][10];



typedef struct {
  int **iter;
  int **attr;
  int ib;
  int istep;
  int sz;
  mtx_t *mtx;
  cnd_t *cnd;
  int *finish_flag;
} thrd_info_t;

typedef struct{
  int **iter;
  int **attr;
  int sz;
  mtx_t *mtx;
  cnd_t *cnd;
  FILE *colorful;
  FILE *black;
  int *finish_flag;
} thrd_write_info_t;




int write_thrd(void* args){
  const thrd_write_info_t *thrd_write_info = (thrd_write_info_t *) args;
  int **iter =  thrd_write_info->iter;
  int **attr =  thrd_write_info->attr;
  int sz = thrd_write_info->sz;
  mtx_t *mtx =  thrd_write_info->mtx;
  cnd_t *cnd =  thrd_write_info->cnd;
  FILE *colorful = thrd_write_info->colorful;
  FILE *black = thrd_write_info->black;
  int *finish_flag = thrd_write_info->finish_flag;
  char *color_row=(char *)malloc(12*sz*sizeof(char));  
  char *black_row=(char *)malloc(12*sz*sizeof(char));

  for(int ix=0; ix<sz; ix++){
    int *attr_ix = attr[ix];
    int *iter_ix = iter[ix];
    
    mtx_lock(mtx);
    while(finish_flag[ix]==0){
      cnd_wait(cnd,mtx);
    }

    
    for(int col=0; col<sz; col++){
      int tmp=iter_ix[col];
      switch (tmp) {
      case 1:
        memcpy(black_row + 12 * col, "005 005 005 ", 12);
        break;
      case 2:
        memcpy(black_row + 12 * col, "010 010 010 ", 12);
        break;
      case 3:
        memcpy(black_row + 12 * col, "015 015 015 ", 12);
        break;
      case 4:
        memcpy(black_row + 12 * col, "020 020 020 ", 12);
        break;
      case 5:
        memcpy(black_row + 12 * col, "025 025 025 ", 12);
        break;
      case 6:
        memcpy(black_row + 12 * col, "030 030 030 ", 12);
        break;
      case 7:
        memcpy(black_row + 12 * col, "035 035 035 ", 12);
        break;
      case 8:
        memcpy(black_row + 12 * col, "040 040 040 ", 12);
        break;
      case 9:
        memcpy(black_row + 12 * col, "045 045 045 ", 12);
        break;
      case 10:
        memcpy(black_row + 12 * col, "050 050 050 ", 12);
        break;
      case 11:
        memcpy(black_row + 12 * col, "056 056 056 ", 12);
        break;
      case 12:
        memcpy(black_row + 12 * col, "061 061 061 ", 12);
        break;
      case 13:
        memcpy(black_row + 12 * col, "066 066 066 ", 12);
        break;
      case 14:
        memcpy(black_row + 12 * col, "071 071 071 ", 12);
        break;
      case 15:
        memcpy(black_row + 12 * col, "076 076 076 ", 12);
        break;
      case 16:
        memcpy(black_row + 12 * col, "081 081 081 ", 12);
        break;
      case 17:
        memcpy(black_row + 12 * col, "086 086 086 ", 12);
        break;
      case 18:
        memcpy(black_row + 12 * col, "091 091 091 ", 12);
        break;
      case 19:
        memcpy(black_row + 12 * col, "096 096 096 ", 12);
        break;
      case 20:
        memcpy(black_row + 12 * col, "100 100 100 ", 12);
        break;
      case 21:
        memcpy(black_row + 12 * col, "107 107 107 ", 12);
        break;
      case 22:
        memcpy(black_row + 12 * col, "112 112 112 ", 12);
        break;
      case 23:
        memcpy(black_row + 12 * col, "117 117 117 ", 12);
        break;
      case 24:
        memcpy(black_row + 12 * col, "122 122 122 ", 12);
        break;
      case 25:
        memcpy(black_row + 12 * col, "127 127 127 ", 12);
        break;
      case 26:
        memcpy(black_row + 12 * col, "132 132 132 ", 12);
        break;
      case 27:
        memcpy(black_row + 12 * col, "137 137 137 ", 12);
        break;
      case 28:
        memcpy(black_row + 12 * col, "142 142 142 ", 12);
        break;
      case 29:
        memcpy(black_row + 12 * col, "147 147 147 ", 12);
        break;
      case 30:
        memcpy(black_row + 12 * col, "153 153 153 ", 12);
        break;
      case 31:
        memcpy(black_row + 12 * col, "158 158 158 ", 12);
        break;
      case 32:
        memcpy(black_row + 12 * col, "163 163 163 ", 12);
        break;
      case 33:
        memcpy(black_row + 12 * col, "168 168 168 ", 12);
        break;
      case 34:
        memcpy(black_row + 12 * col, "173 173 173 ", 12);
        break;
      case 35:
        memcpy(black_row + 12 * col, "178 178 178 ", 12);
        break;
      case 36:
        memcpy(black_row + 12 * col, "183 183 183 ", 12);
        break;
      case 37:
        memcpy(black_row + 12 * col, "188 188 188 ", 12);
        break;
      case 38:
        memcpy(black_row + 12 * col, "193 193 193 ", 12);
        break;
      case 39:
        memcpy(black_row + 12 * col, "198 198 198 ", 12);
        break;
      case 40:
        memcpy(black_row + 12 * col, "204 204 204 ", 12);
        break;
      case 41:
        memcpy(black_row + 12 * col, "209 209 209 ", 12);
        break;
      case 42:
        memcpy(black_row + 12 * col, "214 214 214 ", 12);
        break;
      case 43:
        memcpy(black_row + 12 * col, "219 219 219 ", 12);
        break;
      case 44:
        memcpy(black_row + 12 * col, "224 224 224 ", 12);
        break;
      case 45:
        memcpy(black_row + 12 * col, "229 229 229 ", 12);
        break;
      case 46:
        memcpy(black_row + 12 * col, "234 234 234 ", 12);
        break;
      case 47:
        memcpy(black_row + 12 * col, "239 239 239 ", 12);
        break;
      case 48:
        memcpy(black_row + 12 * col, "244 244 244 ", 12);
        break;
      case 49:
        memcpy(black_row + 12 * col, "249 249 249 ", 12);
        break;
      case 50:
        memcpy(black_row + 12 * col, "255 255 255 ", 12);
        break;
      default:        // Default case
        break;
      }

      //char *conv_color = colormap_conv[iter_ix[col]];
      //memcpy(con_color_row+12*jx, conv_color, 12);
      //memcpy(black_row+12*col,colormap_conv[tmp],12);
      
      switch(attr_ix[col]){
      case 0:
	//fprintf(colorful, "%d %d %d ",180 ,0 ,30 );
	memcpy(color_row+12*col,"180 000 030 ",12);
	break;
      case 1:
	memcpy(color_row+12*col,"000 180 030 ",12);
	break;
      case 2:
	memcpy(color_row+12*col,"000 030 080 ",12);
	break;
      case 3:
	memcpy(color_row+12*col,"180 000 030 ",12);
	break;
      case 4:
	memcpy(color_row+12*col,"180 000 175 ",12);
	break;
      case 5:
	memcpy(color_row+12*col,"180 255 000 ",12);
	break;
      case 6:
	memcpy(color_row+12*col,"155 170 180 ",12);
	break;
      case 7:
	memcpy(color_row+12*col,"070 050 000 ",12);
	break;
      case 8:
	memcpy(color_row+12*col,"150 060 000 ",12);
	break;
      case 9:
	memcpy(color_row+12*col,"000 150 60 ",12);
	break;
      default://about attr_ix[col]=-1
	memcpy(color_row+12*col,"255 255 255 ",12);
	break;
      }
    }//col for loop
    color_row[12*sz-1]='\n';
    black_row[12*sz-1]='\n';
    fwrite(color_row,sizeof(char),12*sz,colorful);
    fwrite(black_row,sizeof(char),12*sz,black);
    mtx_unlock(mtx);
  }	
  return 0;
}



int main_thrd( void *args ){
  //------------------------------
  //structure
  const thrd_info_t *thrd_info = (thrd_info_t*) args;
  int **attr = thrd_info->attr;
  int **iter = thrd_info->iter;
  const int ib = thrd_info->ib;
  const int istep = thrd_info->istep;
  const int sz = thrd_info->sz;
  mtx_t *mtx = thrd_info->mtx;
  cnd_t *cnd = thrd_info->cnd;
  int *finish_flag = thrd_info->finish_flag;
  int degree = degree_global;

  double step = 4.0 / (sz - 1);
  double imag;
   
  //------------------------------
  // one row
  for ( int ix = ib; ix < sz; ix += istep ) {
    double complex c;
    int *attr_ix = attr[ix];
    int *iter_ix = iter[ix];
    int conv;

    
    imag = 2.0 - ix * step;
    for ( int col = 0; col < sz; ++col ) {
      c = -2.0 + col * step + I*imag;//zix[
      for ( conv = 0, attr_ix[col] = -1 ; conv<127; ++conv ) { // newton's iteration
	if ( creal(c)*creal(c)+cimag(c)*cimag(c) <= 1e-6 ) {
	  attr_ix[col] = -1;
	  break;
	}
	if ( fabs(creal(c)) > upper_limit || fabs(cimag(c)) >upper_limit ) {
	  attr_ix[col] = -1;
	  break;
	}
	for ( int ix_root=0; ix_root < degree; ix_root++ ){
	  if ( creal(c-roots[degree-1][ix_root])*creal(c-roots[degree-1][ix_root]) + cimag(c-roots[degree-1][ix_root])*cimag(c-roots[degree-1][ix_root]) < 1e-6 ) {
	    attr_ix[col] = ix_root;
	    break;
	  }
	}
	if ( attr_ix[col] != -1 )
	  break;

	//------------------------------
	switch ( degree ) {// computation
	case 1:
	  c-=(c-1);
	  break;
	case 2:
	  c-=((c*c-1)/(2*c));
	  break;
	case 3:
	  c-=((c*c*c-1)/(3*c*c));
	  break;
	case 4:
	  c-=((c*c*c*c-1)/(4*c*c*c));
	  break;
	case 5:
	  c-=((c*c*c*c*c-1)/(5*c*c*c*c));
	  break;
	case 6:
	  c-=((c*c*c*c*c*c-1)/(6*c*c*c*c*c));
	  break;
	case 7: //use tt replace c^6 can speed up
	  complex double tt = c*c*c*c*c*c;
	  c-=((c*tt-1)/(7*tt));
	  break;
	case 8:
	  c-=((c*c*c*c*c*c*c*c-1)/(8*c*c*c*c*c*c*c));
	  break;
	case 9:
	  c-=((c*c*c*c*c*c*c*c*c-1)/(9*c*c*c*c*c*c*c*c));
	  break;
	case 10:
	  c-=(( c * c * c * c * c * c * c * c * c *c-1)/    (10  *c*c*c*c*c*c*c*c*c));
	  break;
	default:
	  printf("unexpected degree\n");
	  exit(1);
	}
      }// newton iter loop end
      if (conv>50) conv=50;
      iter_ix[col]=conv;
    }// column loop end
  
    mtx_lock(mtx);
    iter[ix] = iter_ix;
    attr[ix] = attr_ix;
    finish_flag[ix] = 1;
    mtx_unlock(mtx);
    cnd_signal(cnd);
  }// end of the row 
  return 0;
}


int main(int argc, char *argv[]){
  //------------------------------
  // roots for x - 1
  roots[0][0] = 1 + 0 * I;
  // roots for x^2 - 1
  roots[1][0] = 1 + 0 * I;
  roots[1][1] = -1 + 0 * I;
  // roots for x^3 - 1
  roots[2][0] = 1 + 0 * I;
  roots[2][1] = -0.5 + 0.86603 * I;
  roots[2][2] = -0.5 - 0.86606 * I;
  // roots for x^4 - 1
  roots[3][0] = 1 + 0 * I;
  roots[3][1] = 0 + 1 * I;
  roots[3][2] = -1 + 0 * I;
  roots[3][3] = 0 - 1 * I;
  // roots for x^5 - 1
  roots[4][0] = 1 + 0 * I;
  roots[4][1] = 0.309017 + 0.951057 * I;
  roots[4][2] = -0.809017 + 0.587785 * I;
  roots[4][3] = -0.809017 - 0.587785 * I;
  roots[4][4] = 0.309017 - 0.951057 * I;
  // roots for x^6 - 1
  roots[5][0] = 1 + 0 * I;
  roots[5][1] = 0.5 + 0.866025 * I;
  roots[5][2] = -0.5 + 0.866025 * I;
  roots[5][3] = -1 - 0 * I;
  roots[5][4] = -0.5 - 0.866025 * I;
  roots[5][5] = 0.5 - 0.866025 * I;
  // roots for x^7 - 1
  roots[6][0] = 1 + 0 * I;
  roots[6][1] = 0.62349 + 0.781831 * I;
  roots[6][2] = -0.222521 + 0.974928 * I;
  roots[6][3] = -0.900969 + 0.433884 * I;
  roots[6][4] = -0.900969 - 0.433884 * I;
  roots[6][5] = -0.222521 - 0.974928 * I;
  roots[6][6] = 0.62349 - 0.781831 * I;
  // roots for x^8 - 1
  roots[7][0] = 1 + 0 * I;
  roots[7][1] = 0.707107 + 0.707107 * I;
  roots[7][2] = 0 + 1 * I;
  roots[7][3] = -0.707107 + 0.707107 * I;
  roots[7][4] = -1 + 0 * I;
  roots[7][5] = -0.707107 - 0.707107 * I;
  roots[7][6] = 0 - 1 * I;
  roots[7][7] = 0.707107 - 0.707107 * I;
  // roots for x^9 - 1
  roots[8][0] = 1 + 0 * I;
  roots[8][1] = 0.766044 + 0.642788 * I;
  roots[8][2] = 0.173648 + 0.984808 * I;
  roots[8][3] = -0.5 + 0.866025 * I;
  roots[8][4] = -0.939693 + 0.34202 * I;
  roots[8][5] = -0.939693 - 0.34202 * I;
  roots[8][6] = -0.5 - 0.866025 * I;
  roots[8][7] = 0.173648 - 0.984808 * I;
  roots[8][8] = 0.766044 - 0.642788 * I;

  //------------------------------
  //data from shell
  for (int i = 1; i < 4; i++) {
    if (sscanf(argv[i], "-t%d", &threads) == 1) {
      //printf("Extracted value: %d\n", threads);
    } else if (sscanf(argv[i], "-l%d", &size) == 1) {
      //printf("Extracted value: %d\n", size);
    }
    else if (sscanf(argv[i], " %d", &degree_global) == 1) {
      //printf("Extracted value: %d\n", degree_global);
    }
    else {
      printf("Invalid input.\n");
      return 1;
    }
  }
  

  //------------------------------
  //file
  FILE *black, *colorful;
  char filename[26];
  sprintf(filename,"newton_attractors_x%d.ppm",degree_global);
  colorful = fopen(filename, "w");
  sprintf(filename,"newton_convergence_x%d.ppm",degree_global);
  black = fopen(filename, "w");
  if (black == NULL || black == NULL) {
    perror("Error opening the file");
    return 1;
  }
  fprintf(black, "P3\n");
  fprintf(black, "%d %d \n", size, size);
  fprintf(black, "255\n");
  fprintf(colorful, "P3\n");
  fprintf(colorful, "%d %d \n", size, size);
  fprintf(colorful, "255\n");

  
  //------------------------------
  const int sz = size;
  int *finish_flag = (int *)malloc(sz*sizeof(int));
  int **attr = (int**) malloc(sz*sizeof(int*));
  int **iter = (int**) malloc(sz*sizeof(int*));
  int *attr_entries = (int*) malloc(sz*sz*sizeof(int));
  int *iter_entries = (int*) malloc(sz*sz*sizeof(int));

  for ( int ix = 0, jx = 0; ix < sz; ++ix, jx += sz ){
    attr[ix] = attr_entries + jx;
    iter[ix] = iter_entries + jx;
    //    z[ix] = zentries + jx;
  }
  for ( int ix = 0; ix < sz*sz; ++ix ){
    attr_entries[ix] = 0;
    iter_entries[ix] = 0;
    //zentries[ix] = 0;
  }
  for ( int ix = 0; ix < sz; ++ix ){
    finish_flag[ix]=0;
  }

  //------------------------------
  //thread initial
  const int nthrds = threads;
  thrd_t thrds[nthrds];
  thrd_info_t thrds_info[nthrds];
  
  thrd_t thrd_write;
  thrd_write_info_t thrd_write_info;

  //mutex initial and condition initial
  mtx_t mtx;
  mtx_init(&mtx, mtx_plain);
  cnd_t cnd;
  cnd_init(&cnd);

  //------------------------------
  //computation thread create
  for ( int tx = 0; tx < nthrds; ++tx ) {
    //thrds_info[tx].z = (double complex**) z;
    thrds_info[tx].attr = attr;
    thrds_info[tx].iter = iter;

    //row switching para
    thrds_info[tx].ib = tx;
    thrds_info[tx].istep = nthrds;
    thrds_info[tx].sz = sz;

    //mutex and condition
    thrds_info[tx].mtx = &mtx;
    thrds_info[tx].cnd = &cnd;

    //
    thrds_info[tx].finish_flag = finish_flag;
    
    //create
    int r = thrd_create(thrds+tx, main_thrd, (void*) (thrds_info+tx));
    if ( r != thrd_success ) {
      printf("failed to create thread\n");
      exit(1);
    }
    //thrd_detach(thrds[tx]);
  }

  //------------------------------
  //write thread create
  thrd_write_info.iter = iter;
  thrd_write_info.attr = attr;
  thrd_write_info.sz   = sz;
  thrd_write_info.mtx  = &mtx;
  thrd_write_info.cnd  = &cnd;
  thrd_write_info.colorful = colorful;
  thrd_write_info.black    = black;
  thrd_write_info.finish_flag = finish_flag;

  int x = thrd_create(&thrd_write, write_thrd, (void*) (&thrd_write_info));
  if ( x != thrd_success ) {
    printf("failed to create thread\n");
    exit(1);
  }


  //------------------------------
  //thread join 
  for(int t=0;t<nthrds;t++){
    thrd_join(thrds[t], NULL);
  }
  thrd_join(thrd_write, NULL);


  //------------------------------
  //free (but i dont know the atter entry and iter entry, maybe we can use them in thrad)
  //free(zentries);
  free(attr_entries);
  free(iter_entries);
  //  free(z);
  free(iter);
  free(attr);

  mtx_destroy(&mtx);
  cnd_destroy(&cnd);

  fclose(black);
  fclose(colorful);

  return 0;
}
 



