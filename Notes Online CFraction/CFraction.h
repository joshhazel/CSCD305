
class CFraction
{
public:
	CFraction(int num = 0, int den = 1);
	CFraction(const CFraction & orig);
	~CFraction(void);

	CFraction & operator=(const CFraction & rhs);
	bool operator==(const CFraction & rhs);
	bool operator!=(const CFraction & rhs);

	friend bool operator==(const CFraction & lhs, const CFraction & rhs);
	friend ostream & operator<<(ostream & out, const CFraction & rhs);
	friend istream & operator>>(istream & in, CFraction & rhs);


private:
	int * m_den;
	int * m_num;
};

