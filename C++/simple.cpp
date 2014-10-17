class Test
{
public:
	struct struct1
	{
		int someInts[2];
		int moreInts;
	};

	struct struct2
	{
		int someMoreInts[2];
	};

	void count(int count);
	void countCount(int count);
};

void Test::count(int count)
{
	int result = 10;
	for(int i = 0; i < count; ++i)
	{
		++result;
	}
}

int main()
{
	int test = 5 + 1;
	Test testObj{};
	testObj.count(5);
}