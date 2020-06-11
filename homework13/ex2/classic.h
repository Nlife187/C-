// classic.h -- base class

#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd
{
private:
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    virtual Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
    char * major;
public:
    Classic(const char * m, const char * s1, const char * s2, int n, double x);
    Classic(const char * m, const Cd & d);
    Classic();
    virtual void Report() const;
    virtual Classic & operator=(const Classic & cc);
    ~Classic();
};

#endif
