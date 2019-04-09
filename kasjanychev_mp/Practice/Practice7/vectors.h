#pragma once

class Vectors
{
private:
	int s;
	double *arr;
public:
	Vectors();
	Vectors(int x);
	Vectors(const Vectors& vct);
	~Vectors();
	Vectors operator+ (const Vectors & temp) const;
	Vectors operator- (const Vectors & temp) const;
};