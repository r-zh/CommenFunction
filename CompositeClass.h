//
//  CompositeClass.h
//  CommenFunction
//
//  Created by Rui Zhou on 2021-02-10.
//

#ifndef CompositeClass_h
#define CompositeClass_h

// time.h – definition of the class Time

class Time {
  public:
    Time();
    void setTime( int, int ,int ); // sets hours, minutes, and seconds
    void printTime() const;      // prints time on the screen
  private:
    int hour, minute, second;
};

// date.h – definition of the class Date

class Date {
   public:
     // sets day, month, year, hours, minutes, seconds
      Date(int, int, int, int, int, int);
      void printDate() const;   // print date to the screen
   private:
      int day, month, year;
      Time time;
};


#endif /* CompositeClass_h */
