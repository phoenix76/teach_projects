#include <iostream>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void ShowStruct(box);
void Process(box*);

int main()
{
	box obj = { "box", 10.0f, 10.0f, 10.0f, 0.0f };
	ShowStruct(obj);
	std::cout << "\n\n";
	Process(&obj);
	ShowStruct(obj);

	std::cin.get();
	return 0;
}

void ShowStruct(box b)
{
	std::cout << "Maker " << b.maker << '\n';
	std::cout << "Height " << b.height << '\n';
	std::cout << "Width " << b.width << '\n';
	std::cout << "Length " << b.length << '\n';
	std::cout << "Volume " << b.volume << '\n';
}

void Process(box *bPtr)
{
	bPtr->volume = bPtr->height * bPtr->width * bPtr->length;
}