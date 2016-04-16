#pragma once
class Dyn_String
{
	char *tab;
public:
	Dyn_String(const char* );
	Dyn_String(const Dyn_String &);

	unsigned int Size() const;
	const char* Cstr() const;

	void operator += (const char*);
	void operator ! ();

	~Dyn_String();
};

