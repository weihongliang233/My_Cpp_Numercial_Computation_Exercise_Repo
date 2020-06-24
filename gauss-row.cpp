#include<stdio.h>
#include<math.h>
#define N 9

void gauss_row(double a[N][N+1]){
	double x[N];
	double s,t;
	int i,j,m,k;
	for(i=0;i<N-1;i++){
		//选主元的消元过程
		s=a[i][i];
		m=i;
		for(j=i+1;j<N;j++){
			//ѡ��Ԫ
			if(fabs(a[j][i])>s)
				m=j;
		}
		for(j=i;j<N+1;j++){
			//����m����i��
			t=a[i][j];
			a[i][j]=a[m][j];
			a[m][j]=t;
		}
		for(j=i+1;j<N;j++){
			//��Ԫ
			t=a[j][i]/a[i][i];
			for(k=i+1;k<N+1;k++)
				a[j][k]=a[j][k]-t*a[i][k];
		}
	}
	x[N-1]=a[N-1][N]/a[N-1][N-1];

	for(i=N-2;i>=0;i--){
		//�ش����
		s=a[i][N];
		for(j=i+1;j<N;j++)
			s=s-a[i][j]*x[j];
		x[i]=s/a[i][i];
	}
	for(i=0;i<N;i++)//�����
		printf("x[%d]=%.6lf\n",i+1,x[i]);
}

int main(){
	double A[N][N+1]={{31,-13,0,0,0,-10,0,0,0,-15},
					{-13,35,-9,0,-11,0,0,0,0,27},
					{0,-9,31,-10,0,0,0,0,0,-23},
					{0,0,-10,79,-30,0,0,0,-9,0},
					{0,0,0,-30,57,-7,0,-5,0,-20},
					{0,0,0,0,-7,47,-30,0,0,12},
					{0,0,0,0,0,-30,41,0,0,-7},
					{0,0,0,0,-5,0,0,27,-2,7},
					{0,0,0,-9,0,0,0,-2,29,10}};
	gauss_row(A);
	return 0;
}










