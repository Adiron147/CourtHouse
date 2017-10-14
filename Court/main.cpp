#pragma warning(disable: 4996)

#include <iostream>
#include <ctime>
using namespace std;
#include "CourtHouse.h"
#include "CourtRoom.h"
#include "CourtWorker.h"
#include "Judge.h"
#include "Jury.h"
#include "JuryMember.h"
#include "Lawyer.h"
#include "Party.h"
#include "Person.h"
#include "Trial.h"

static const int LEN = 20;

CourtHouse* initCourtHouse();

void addJudgesToCourtHouse(CourtHouse& courtHouse);

void insertTrialsToCourtHouse(CourtHouse& courtHouse);

void insertJuryToTrial(Trial& trial);

void showAllJudges(const CourtHouse& courtHouse);

void showInformationForJudge(const CourtHouse& court, const char* name);

void showTrialsByRoomId(const CourtHouse& court, int roomId);

void showAvailableRoomsForTrialsInACertainHour(const CourtHouse& court, tm& start, tm& end);

void showTrialsBySubject(const CourtHouse& court, Trial::eTrialSubject subject);

void freeCourtHouse(CourtHouse* courtHouse);

int main() 
{
    try
    {
        int index = 0;
        int roomId = 0;

        /**
         tm explanation:
         tm is a struct defined in ctime
         you can also initiate it like this :

         tm myTm = {seconds, minutes, hours, day in month, month, year .... and there are more parameters here}

         the other parameters are not important for us in this system.

         */

        tm start, end;

        start.tm_year = end.tm_year = 2017;
        start.tm_mon = end.tm_mon = 9;
        start.tm_mday = end.tm_mday = 1;

        start.tm_hour = 9;
        end.tm_hour = 10;
    

    
        CourtHouse* courtHouse = initCourtHouse();

		if(!courtHouse)
		{
			exit(1);
		}

        addJudgesToCourtHouse(*courtHouse);

        insertTrialsToCourtHouse(*courtHouse);

        //  (*courtHouse)[index][index] is a Trial: CourtHouse[CourtRoom_Number][Trial_Number_in_the_room]
        insertJuryToTrial((*courtHouse)[index][index]);

        showAllJudges(*courtHouse);

        showInformationForJudge(*courtHouse, "Judge 1");

        showTrialsByRoomId(*courtHouse, roomId);

        showAvailableRoomsForTrialsInACertainHour(*courtHouse, start, end);

        showTrialsBySubject(*courtHouse, Trial::CRIMINAL);

        freeCourtHouse(courtHouse);
        
    }
    catch(...)
    {
        cout << "Something went wrong" << endl;
    }
}


CourtHouse* initCourtHouse()
{
    try
    {
        const int size = 3;
        CourtHouse* court = new CourtHouse("Israel", "Tel Aviv", "Afeka Court House", size);
        return court;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
		return NULL;
    }
	
	
}

void addJudgesToCourtHouse(CourtHouse& courtHouse)
{
    try
    {
        int size = 3;

        for( int i = 0 ; i < size ; i++)
        {
            char name[LEN];
            sprintf(name,"Judge %d",(i+1));
            int id = (i+1);
            char* academicInst = strdup("Institute");
            int graduateYear = 1990+i;
            int startYear = 2000+i;
            int salary = (i+1)*10000;

            Judge* judge =  new Judge(name, id, academicInst, graduateYear, startYear, salary);
            courtHouse.addJudge(judge);

            delete academicInst;
        }
    }
    catch (const char* message)
    {
        cout << message << endl;
    }
    catch(int value)
    {
        cout << "One of the following values is inccorrect! id / graduateYear / salary with value: " << value << endl;
    }
}

void insertTrialsToCourtHouse(CourtHouse& courtHouse)
{
    try
    {
        const int numOfTypes = Trial::NUM_OF_TYPES;
        int size = courtHouse.getNumOfCourtRooms();

        tm start, end;

        start.tm_year = end.tm_year = 2017;
        start.tm_mon = end.tm_mon = 9;
        start.tm_mday = end.tm_mday = 1;

        start.tm_hour = 7;
        end.tm_hour = 8;

        for(int i = 0 ; i < size ; i++)
        {
            char name[LEN];
            sprintf(name,"Judge %d",(i+1));
            Judge* judge = courtHouse.getJudgeByName(name);
            if(judge != nullptr)
            {
          
                Party *defense = new Party("Defendant", Party::DEFENSE, Party::SINGLE_PERSON, "Defense Lawyer", 10+i, "Yale", 1980+i);
                Party *prosecution =new Party("Prosecutor",Party::PROSECUTION, Party::SINGLE_PERSON, "Prosecution Lawyer", 10+i, "Harvard", 1980+i+1);
                if(!courtHouse[i].isTaken(start,end) && !(*courtHouse.getJudgeByName(name)).isBusy(start,end))
                {
                    Trial* currTrial = new Trial((Trial::eTrialSubject) (i & numOfTypes), *judge, *defense, *prosecution, courtHouse[i], start, end);

                    courtHouse[i].addTrial(*currTrial);
                }
                start.tm_hour++;
                end.tm_hour++;
            }
        }
    }
    catch (const char* message)
    {
        cout << message << endl;
    }
    catch(int value)
    {
        cout << "One of the following values is inccorrect! id / graduateYear with value: " << value << endl;
    }
}

void insertJuryToTrial(Trial& trial)
{
    try
    {
        const int size = 5;
        JuryMember** juryMembers = new JuryMember*[size];

        for(int i = 0 ; i < size ; i++)
        {
            juryMembers[i] = new JuryMember("JuryMember" ,(i+100));
        }

        Jury* jury = new Jury(juryMembers, size);
        trial.setJury(jury);
    }
    catch (int id)
    {
        cout <<"Wrong id: "<< id << ", value can not be negative" << endl;
    }
    catch(const char* message)
    {
        cout << message << endl;
    }
}

void showAllJudges(const CourtHouse& courtHouse)
{
    int size = courtHouse.getNumOfJudges();
    const Judge*const* allJudges = courtHouse.getAllJudges();
    cout << "The court house judges are: " << endl;

    for( int i = 0 ; i < size ; i++)
    {
        cout << *allJudges[i] << endl;
    }
}

void showInformationForJudge(const CourtHouse& court,const char* name)
{
    const Judge* judge = court.getJudgeByName(name);
    if(judge)
        cout << endl<< endl<< "Searched "<< name << " and found: " << endl << *judge << endl;
    else
        cout << "The judge with the name " << name << "was not found";
}

void showTrialsByRoomId(const CourtHouse& court, int roomId)
{
    try
    {
        if(roomId < court.getNumOfCourtRooms() && roomId >=0)
        {
            int numOfTrials = court[roomId].getNumOfTrials();
            if(numOfTrials == 0)
            {
                cout << "There are currently no trials to show in this room" << endl;
                return;
            }
            else
            {
                cout << endl << endl << endl << "The trials in room #" << roomId << " are: "<< endl;
                for(int i = 0 ; i < numOfTrials ; i++)
                {
                    cout << court[roomId][i] << endl;
                }
            }
        }
        else
        {
            cout << "The room id you entered does not exists!" << endl;
        }
    }
    catch (int trialId)
    {
        cout << "There is no trial with id: " <<trialId << " in room #" << roomId << endl;
    }
}

void showAvailableRoomsForTrialsInACertainHour(const CourtHouse& court, tm& start, tm& end)
{
    int size = court.getNumOfCourtRooms();

    cout << endl << endl << "The rooms that are available at this time are: " << endl;
    for(int i = 0 ; i < size ; i++)
    {
        if(!court[i].isTaken(start, end))
        {
            cout << "Room #"<< court[i].getRoomNumber() << endl;
        }
    }
}

void showTrialsBySubject(const CourtHouse& court, Trial::eTrialSubject subject)
{
    int size = court.getNumOfCourtRooms();

    cout << endl << endl << "The trials discussing the subject " << Trial::strTrialSubject[subject] << " are: " << endl;
    for(int i = 0 ; i < size ; i++)
    {
        int numOfTrials = court[i].getNumOfTrials();
        for(int j = 0 ; j < numOfTrials ; j++)
        {
            if(court[i][j].getSubject() == subject)
            {
                cout << court[i][j] << endl << endl;
            }
        }
    }

}

void freeCourtHouse(CourtHouse* courtHouse)
{
    delete courtHouse;
}
