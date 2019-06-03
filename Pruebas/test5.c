int main()
{
	int a, b;
	a = b++;
	a = a * 1 + 1;

	if(a == 1){
		a = b;
	}
}