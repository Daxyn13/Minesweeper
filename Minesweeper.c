#include <stdio.h>
void random_narkes(char ** Mat,int M, int N, int K);
void write_info(char ** Mat,int M, int N);

int main() {
		
	char **Mat, Pinakas;
	int M, N, K, i, j;
	
	printf("Plhktrologhse ton arithmo twn grammwn: ");
	scanf("%d",&M);
	printf("Plhktrologhse ton arithmo twn sthlwn: ");
	scanf("%d",&N);
	printf("Plhktrologhse ton arithmo twn mines: ");
	scanf("%d",&K);
	
//	printf("M: %d, N: %d,  K: %d\n", M, N, K);
	if( M * N < K ) {
		printf("Dwse mikrotrero arithmo narkwn!");
	}
	
	Mat = (char **) malloc (M * sizeof(char *));
	for ( i  = 0; i < M; i++) {
		Mat[i] = (char *) malloc (N * sizeof(char ));
	}
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			Mat[i][j] = ' ';
		}
	}
	//arxikopoihsh tou pinaka

	random_narkes(Mat, M, N, K);
	write_info(Mat, M, N);

	FILE *fptr;

	   // opening file in writing mode
	   fptr = fopen("Minesweeper.txt", "w");
	
	   // exiting program 
	   if (fptr == NULL) {
	       printf("Error!");
	       exit(1);
	   }
	for (i = 0; i<M; i++ ){
		for(j = 0; j<N; j++){
	        printf("%c ", Mat[i][j]);
	    }
		printf("\n");    
	}
	
	
    for (i = 0; i<M; i++ ){
		for(j = 0; j<N; j++){
	        fprintf(fptr, "%c ", Mat[i][j]);
	    }
		fprintf(fptr,"\n");    
	}
	   
	   fclose(fptr);
	   return 0;
	
}

void random_narkes(char ** Mat,int M, int N, int K)
{
	int i,x,y;
	for ( i = 1; i <= K; i++){
	do 
	{
		x = rand() % M;
		y = rand() % N;
	}
	while (Mat[x][y] == 'B');
	Mat[x][y] = 'B';
	
	}
}

void write_info(char ** Mat,int M, int N){
	int i,j;
	int counter = 0;
	for (i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			counter = 0;

			if (Mat[i][j] != 'B')
			{
			
				if (i == 0 ){ 
				
					if(j-1 >= 0 && Mat[i][j-1] == 'B') counter++;
					if(Mat[i+1][j] == 'B') counter++;
					if(j+1 <= N-1 && Mat[i][j+1] == 'B') counter++;
					
					Mat[i][j] = counter + '0';
				}
				
				else if (i == M - 1 ){ 
				
					if(j-1 >= 0 && Mat[i][j-1] == 'B') counter++;
					if(Mat[i-1][j] == 'B') counter++;
					if(j+1 <= N-1 && Mat[i][j+1] == 'B') counter++;
					
					Mat[i][j] = counter + '0';
				}
				
				else { 
					if(j-1 >= 0  && Mat[i][j-1] == 'B') counter++;
					if(Mat[i-1][j] == 'B') counter++;
					if(Mat[i+1][j] == 'B') counter++;
					if(j+1 <= N-1 && Mat[i][j+1] == 'B') counter++;
					
					Mat[i][j] = counter + '0';
				}
			
			}
			
		}
	}
}



