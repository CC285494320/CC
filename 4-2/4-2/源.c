//1.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//#include<stdio.h>
//int main(){
//	int m = 1999;
//	int n = 2299;
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++){
//		if (((m >> i)&1) != ((n >> i)&1))
//			count++;
//	}
//	printf("count = %d\n", count);
//	system("pause");
//	return 0;
//}
//
//2.��д������
//unsigned int  reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//#include<stdio.h>
//unsigned int reverse_bit(unsigned int value){
//	int i = 0;
//	unsigned int sum = 0;
//	int tem = 0;
//	for (i = 0; i < 32; i++){
//		tem = ((value >> i) & 1);
//		if (tem==1)
//			sum+=(tem)*(1<<(31-i));
//	}
//	return sum;
//}
//int main(){
//	int n = 25;
//	unsigned int ret = reverse_bit(n);
//	printf("%u\n",ret);
//	system("pause");
//	return 0;
//}
//
//3.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//int main(){
//	int a = 0;
//	int b = 0;
//	scanf("%d%d",&a,&b);
//	int ave = a / 2 + b / 2;
//	if (((a % 2) && (b % 2)) == 1)
//		ave = ave + 1;
//	printf("ave= %d\n",ave);
//	system("pause");
//	return 0;
//}
//
//4.һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ����ҳ�������֡���ʹ��λ���㣩
//#include<stdio.h>
//int main(){
//	int arr[5] = { 1, 1, 2, 2, 3};
//	int bit[5] = { 0 };
//	int i = 0,j = 0;
//	int value = 0;
//	int num1 = 0;
//	int num2 = 0;
//	int count = 0;
//	for (i = 0; i < 5; i++){
//		for (j = 0; j<5; j++){
//			if (j!=i && arr[i] == arr[j]){
//				bit[i]++;
//				break;
//			}
//		}
//	}
//	for (i = 0; i < 5; i++){
//		if (bit[i]==0)
//		printf("%4d ",arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//
//4.һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ����ҳ�������֡���ʹ��λ���㣩
//
//
//#include<stdio.h>
//#define N 10
//int main(){
//	int arr[N] = { 1, 1, 2, 4, 3, 5, 6, 5};
//	int bit[N] = { 0 };
//	int i = 0,j = 0;
//	for (i = 0; i < N; i++){
//		for (j = 0; j<N; j++){
//			if (j != i && (arr[i] ^ arr[j]) == 0){
//				bit[i]++;
//			}
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		if (bit[i] == 0)
//			printf("%d\n", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
////
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[] = { 3, 5, 9, 2, 5, 3, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0, find = 0;
	for (; i<size; i++)
	{
		find ^= arr[i];//ѭ�������������
	}
	printf("%d\n", find);
	system("pause");
	return 0;
}