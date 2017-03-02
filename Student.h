#ifndef Student_h_
#define Student_h_

class SahulatCard;

class Student {
private:
    int StudentID;
    SahulatCard* sahulatCard;
public:
    Student(): StudentID(0), sahulatCard(0)
    {}

    ~Student()
    {
        sahulatCard = 0;
    }
};


#endif // Student_h_
