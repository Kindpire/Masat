//
//  timer.h
//  UniverseMasat
//
//  Created by pf.zcoder on 21/01/2013.
//
//

#ifndef UniverseMasat_timer_h
#define UniverseMasat_timer_h

class timer
{
public:
    int timer_count = 0;
    int timer_base = 1000;
    bool timer_start = false;
    int timer_add = 1;
    
    void start()
    {
        timer_start = true;
    }
    void stop()
    {
        timer_start = false;
    }
    void run()
    {
        if( timer_start )
        {
            timer_count += timer_add;
            
            if (timer_count > timer_base || timer_count < 0) {
                timer_add *= -1;
            }
        }
    }

};

#endif
