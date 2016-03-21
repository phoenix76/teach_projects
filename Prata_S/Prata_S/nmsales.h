namespace SALES
{
	const int quarters = 4;
	struct Sales
	{
		double sales[quarters];
		double average;
		double max;
		double min;
	};

	void set_sales(Sales &s, const double arr[], int n);
	void set_sales(Sales &s);
	void show_sales(const Sales &s);
}