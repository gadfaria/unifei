#ifndef NUMLONGO_H
#define NUMLONGO_H
#define T_NUM 30

class NumLongo
{
	private:
		static int count;
		int num[T_NUM];
	
	public:
		NumLongo();
		~NumLongo();
		
		void somar(NumLongo);
		void subtrair(NumLongo);
		
		void digitar();
		void imprimir();
	
		
};


#endif
