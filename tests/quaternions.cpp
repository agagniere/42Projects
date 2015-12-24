
typedef union	s_quater
{
	double		matrix[4];
	struct
	{
		double		a;
		union
		{
			double	v[3];
			struct
			{
				double b;
				double c;
				double d;
			};
		};
	};
}				t_quater;


int main(void)
{
	t_quater q;

	q = (t_quater){0,0,0,0};
	return (0);
}
