#include <stdio.h>
struct stu {
	int kh;
	float cj;
	char name[20], sex;
};
int main() {
	struct stu a[5] = {
		{100, 55, "AA", 'm'},
		{101, 96, "BB", 'm'}, 
		{102, 50, "CC", 'w'}, 
		{103, 98, "DD", 'w'}, 
		{104, 99, "EE", 'w'}
	};
	float sum = 0;
	for(int i = 0; i < 5; i++) {
		sum += a[i].cj;
	}
	printf("%f", sum/5);
	return 0;
}
