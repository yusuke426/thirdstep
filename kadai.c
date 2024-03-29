#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STUDENT_COUNT 20
int main(){
	float sci[STUDENT_COUNT] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92,
		       36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70};
	float eng[STUDENT_COUNT] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86,
		       29, 56, 89, 23, 65, 84, 64, 27, 86, 84};
	float stu_hensati[STUDENT_COUNT][2], tmp1, tmp2;
	float sci_hensa, eng_hensa, sci_ave, eng_ave, sci_sum = 0, eng_sum = 0;
	int i, j;

	for(i=0;i<STUDENT_COUNT;i++){
		sci_sum += sci[i];
		eng_sum += eng[i];
	}
	sci_ave = sci_sum / STUDENT_COUNT;
	eng_ave = eng_sum / STUDENT_COUNT;

	for(i=0;i<STUDENT_COUNT;i++){
		tmp1 += pow((sci[i] - sci_ave), 2);
		tmp2 += pow((eng[i] - eng_ave), 2);
	}
	sci_hensa = sqrt(tmp1 / STUDENT_COUNT);
	eng_hensa = sqrt(tmp2 / STUDENT_COUNT);

	printf("~理科~\n平均点: %f, 標準偏差: %f, 合計点: %f\n", sci_ave, sci_hensa, sci_sum);
	printf("~英語~\n平均点: %f, 標準偏差: %f, 合計点: %f\n", eng_ave, eng_hensa, eng_sum);
	
	for(i=0;i<STUDENT_COUNT;i++){
		stu_hensati[0][i] = (sci[i] - sci_ave) / (sci_hensa) * 10 + 50;
	}
	for(i=0;i<STUDENT_COUNT;i++){
		stu_hensati[1][i] = (eng[i] - eng_ave) / (eng_hensa) * 10 + 50;
	}

	printf("~偏差値~\n");
	for(i=0;i<STUDENT_COUNT;i++){
		printf("~生徒%d~ 理科: %.2f, 英語: %.2f\n", i+1, stu_hensati[0][i], stu_hensati[1][i]);
}

	for(i=0;i<STUDENT_COUNT;i++){
		for(j=i+1;j<STUDENT_COUNT;j++){
			if(sci[i] < sci[j]){
				tmp1 = sci[i];
				sci[i] = sci[j];
				sci[j] = tmp1;
			}
			if(eng[i] < eng[j]){
				tmp2 = eng[i];
				eng[i] = eng[j];
				eng[j] = tmp2;
			}
		}
	}

	printf("~理科~\n");
	for(i=0;i<STUDENT_COUNT;i++){
		printf("%.1f ", sci[i]);
	}

	printf("\n~英語~\n");
	for(i=0;i<STUDENT_COUNT;i++){
		printf("%.1f ", eng[i]);
	}

	
	return 0;
}
