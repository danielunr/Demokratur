#ifndef PERSON_H
#define PERSON_H

class Person{
    protected:
        long id;
    public:
        Person();
        ~Person();
        Person(long id);
        long getId();
        void setId(long id);
};

#endif // PERSON_H
