#include<cstdio>
template<typename T>struct mem{using type = T; T*value=NULL; T*end=NULL;};


template<typename T>void print(T n);
template<typename T>void println(T n){print(n);putc('\n',stdout);}
template<typename T>void print(mem<T> n){T*e = n.value;print('[');for(;;){print(*e++);if(e<n.end)print(' ');else break;}print(']');}

template<>void print(int n){printf("%d",n);}
template<>void print(short n){printf("%d",n);}
template<>void print(unsigned short n){printf("%d",n);}
template<>void print(unsigned n){printf("%u",n);}
template<>void print(long n){printf("%ld",n);}
template<>void print(long unsigned n){printf("%lu",n);}
template<>void print(long long n){printf("%lld",n);}
template<>void print(long long unsigned n){printf("%llu",n);}
template<>void print(float n){printf("%f",n);}
template<>void print(double n){printf("%f",n);}
template<>void print(long double n){printf("%Lf",n);}
template<>void print(char const*n){printf("%s",n);}
template<>void print(char n){putc(n,stdout);}


/*
a = [1 2 3 4 5 6 7 8 9]
m = 3
n = 3
then [[1 2 3] [4 5 6] [7 8 9]]
goes [[1 4 7] [2 5 8] [3 6 9]]
[1 2 3 4 5 6 7 8 9]
[1 4 7 2 5 8 3 6 9]
(1 1)(2 4)(3 7)(4 2)(5 5)(6 8)(7 3)(8 6)(9 9)
(2 4)(3 7)(6 8)

a = [1 2 3 4 5 6]
m = 2
n = 3
then [[1 2 3] [4 5 6]]
goes [[1 4] [2 5] [3 6]]
[1 2 3 4 5 6]
[1 4 2 5 3 6]
(1 1)(2 3)(3 5)(4 2)(5 4)(6 6)
(2 3)(3 5)(5 4)(4 2)
*/
template <typename T, size_t M, size_t N>
T* transpose(T* a)
{
	T *e = a+(M*N);
	T t[(M*N)];
	for(size_t i = 0; i < M; i++)
	for(size_t j = 0; j < N; j++)
	{
		t[j*M+i] = a[i*N+j];
	}
	for(size_t i = M*N; i;)
	{
		*e-- = t[i--];
	}
	return a;
}

void inline test_print()
{
	println("Hello, World!");
	println(42);
	println(9000.1);
	println(69.f);
	println(50.L);
	println((unsigned short)(sizeof(short)));
	println((long)(sizeof(long)));
	println((long long)(sizeof(long long)));
	println(~0U);
	println(~0UL);
	println(~0ULL);
	println((size_t)42);
	print('\n');
}
int main()
{
	int a[]{0, 1, 2, 3, 4, 5};
	mem<int>amem{a, a+6};
	println(amem);
	transpose<int, 3, 2>(a);
	println(amem);
	return 0;
}

