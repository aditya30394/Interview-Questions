/*
Elements of Programming Interviews
Page 32
*/
int SmallestNonConsructibleValue(vector<int>& A)
{
	sort(A.begin(),A.end());
	int max_constructible_value=0;
	for(int& a:A)
	{
		if(a>max_constructible_value+1)
		{
			break;
		}
		max_constructible_value += a;
	}
	return max_constructible_value+1
}