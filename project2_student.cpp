#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "stemmer.h"
#include <iomanip>
#include<array>
using namespace std;

string readBook(string path)
{
    string text;
    fstream newfile;
    newfile.open(path,ios::in);  // open a file to perform write operation using file object
    if(newfile.is_open()){   //checking whether the file is open
        string line;
        while(getline(newfile, line)){ //read data from file object and put it into string.
            text += line;
        }
        newfile.close(); //close the file object.
    }
    return text;
}

int main(){
  
string book1 = readBook("littlewomen.txt");   
string book2 = readBook("littlemen.txt");
string book1sub;
string book2sub;

string delimiters = " , . ! ? "" - _ '' ! ; : []";

vector<string> anger={"Ordeal", "Outrageousness", "Provoke", "Repulsive", "Scandal", "Severe", "Shameful", "Shocking", "Terrible", "Tragic", "Unreliable", "Unstable", "Wicked", "Aggravate", "Agony", "Appalled", "Atrocious", "Corrupting", "Damaging", "Deplorable", "Disadvantages", "Disastrous", "Disgusted", "Dreadful", "Eliminate", "Harmful", "Harsh", "Inconsiderate", "enraged", "offensive", "aggressive", "frustrated", "controlling", "resentful", "malicious", "infuriated", "critical", "violent", "vindictive", "sadistic", "spiteful", "furious", "agitated", "antagonistic", "repulsed", "quarrelsome", "venomous", "rebellious", "exasperated", "impatient", "contrary", "condemning", "seething", "scornful", "sarcastic", "poisonous", "jealous", "revengeful", "retaliating", "reprimanding", "powerless", "despicable", "self-hating", "desperate", "alienated", "pessimistic", "dejected", "vilified", "unjustified", "violated"};
string angerStem;
int angercount = 0;
int angercount2 = 0;

vector<string> helplessness={"doubtful", "uncertain", "indecisive", "perplexed", "embarrassed", "hesitant", "disillusioned", "distrustful", "misgiving", "unsure", "tense", "stressed", "uncomfortable", "dishonest", "disdainful", "manipulative", "judgmental", "argumentative", "authoritative", "condescending", "distracted", "disoriented", "off-kilter", "frenzied", "blushing", "awkward", "incapable", "paralyzed", "fatigued", "inferior", "vulnerable", "distressed", "pathetic", "distraught", "doomed", "overwhelmed", "incompetent", "incapacitated", "trapped", "squirming", "jittery", "woozy", "twitching", "compulsive", "uncaring", "uninterested", "unresponsive", "terrified", "suspicious", "anxious", "alarmed", "panicked", "threatened", "cowardly", "insecure", "Deceived" , "Helplessness", "Disempowered"};
string helplessStem;
int helplessCount=0;
int helplessCount2=0;

vector<string> happy={"blissful", "joyous", "delighted", "overjoyed", "gleeful", "thankful", "festive", "ecstatic", "satisfied", "cheerful", "sunny", "elated", "jubilant", "jovial", "fun-loving", "lighthearted", "glorious", "innocent", "child-like", "gratified", "euphoric", "world", "playful", "courageous", "energetic", "liberated", "optimistic", "frisky", "animated", "spirited", "thrilled", "wonderful", "funny", "intelligent", "exhilarated", "spunky", "youthful", "vigorous", "tickled", "creative", "constructive", "helpful", "resourceful", "comfortable", "pleased", "encouraged", "surprised", "content", "serene", "bright", "blessed", "Vibrant", "Bountiful", "Glowing"};
string happyStem;
int happyCount=0;
int happyCount2=0;

vector<string> inspired={"motivated", "eager", "keen", "earnest", "inspired", "enthusiastic", "bold", "brave", "daring", "hopeful", "upbeat", "assured", "clear", "balanced", "fine", "okay", "grateful", "carefree", "adequate", "fulfilled", "genuine", "authentic", "forgiving", "sincere", "uplifted", "unburdened", "confident", "self-sufficient", "reliable", "sure", "unique", "dynamic", "tenacious", "cooperative", "productive", "exuberant", "responsive", "conscientious", "approving", "honored", "privileged", "adaptable", "Empowered", "Focused", "Capable"};
string inspiredStem;
int inspiredCount=0;
int inspiredCount2=0;

vector<string> relaxed={"calm", "comfortable", "content", "quiet", "certain", "relaxed", "serene", "bright", "blessed", "balanced", "grateful", "carefree", "fulfilled", "genuine", "authentic", "forgiving", "sincere", "uplifted", "unburdened", "confident", "self-sufficient", "glowing", "radiant", "beaming", "reflective", "smiling", "grounded", "unhurried", "open-minded", "efficient", "non-controlling", "unassuming", "trusting", "supported", "fluid", "light", "spontaneous", "aware", "healthy", "meditative", "still", "rested", "waiting", "laughing", "graceful", "natural", "steady", "centered", "placid", "Clear", "Stoic", "Aligned"};
string relaxedStem;
int relaxedCount=0;
int relaxedCount2=0;

vector<string> safe={"accurate", "instantly", "Advantage", "Always", "Bargain", "Certain", "Certainly", "Confident", "Convenient", "Definitely", "Delighted", "Easy", "Ecstatic", "Effective", "Emphasize", "Extremely", "Freedom", "Guaranteed", "Introducing", "First ever", "Investment", "conscientious", "approving", "honored", "privileged", "adaptable", "relaxed", "Astonishing", "Astounded", "assured", "fulfilled", "genuine", "authentic", "self-sufficient", "reliable", "sure", "secure", "stable", "honest", "truthful", "supportive", "excellent", "responsible", "solid", "trusting", "supported", "Absolutely", "Bargain", "clarity", "transparency", "humility"};
string safeStem;
int safeCount=0;
int safeCount2=0;

vector<string> urgency={"magical", "Instantly", "Magnificent", "Miracle", "Important", "Profitable", "Proven", "Quick", "Remarkable", "Results", "Revolutionary", "Safe", "Save", "Sensational", "Should", "Startling", "Superb", "Superior", "Tremendous", "Truly", "Trustworthy", "Urge", "Worthwhile", "Deadline", "Limited", "Seize", "bargain", "Discount", "Explode", "Extra", "Fortune", "Freebie", "Jackpot", "Reduced", "Instant", "Skyrocket", "Immediately", "Imminently"};
string urgencyStem;
int urgencyCount=0; 
int urgencyCount2=0;
 
size_t pos = book1.find_first_of(delimiters);
pos != string::npos;


	for(int i=0; i<book1.length(); i++)
	{

		size_t pos = book1.find_first_of(delimiters);

		book1sub = book1.substr(0,pos);
		book1sub = stemString(book1sub);
		
		for(int j=0; j<anger.size(); j++)
		{
			angerStem=stemString(anger[j]);
		
				if(book1sub == angerStem)
				{

					angercount++;

				}
		
		}
		
		for(int j=0; j<helplessness.size(); j++)
		{
			helplessStem=stemString(helplessness[j]);
		
				if(book1sub == helplessStem)
				{

					helplessCount++;

				}
		
		}
	
		for(int j=0; j<happy.size(); j++)
		{
			happyStem=stemString(happy[j]);
		
				if(book1sub == happyStem)
				{

					happyCount++;

				}
		
		}
		
		for(int j=0; j<inspired.size(); j++)
		{
			inspiredStem=stemString(inspired[j]);
		
				if(book1sub == inspiredStem)
				{

					inspiredCount++;

				}
		
		}
	
		for(int j=0; j<relaxed.size(); j++)
		{
			relaxedStem=stemString(relaxed[j]);
		
				if(book1sub == relaxedStem)
				{

					relaxedCount++;

				}
		
		}
		
		for(int j=0; j<safe.size(); j++)
		{
			safeStem=stemString(safe[j]);
		
				if(book1sub == safeStem)
				{

					safeCount++;

				}
		
		}
	
		for(int j=0; j<urgency.size(); j++)
		{
			urgencyStem=stemString(urgency[j]);
		
				if(book1sub == urgencyStem)
				{

					urgencyCount++;

				}
		
		}
	
	
	//cout << book1sub << endl;

	book1=book1.erase(0 , pos + 1);



}	
	
cout << "Emotion for 'Little Women': " << endl;
cout << "Anger: " << angercount << endl;	
cout << "Confusion & Helplessness: " << helplessCount << endl;
cout << "Happy & Alive: " << happyCount << endl;
cout << "Inspired: " << inspiredCount << endl;
cout << "Relaxed & Peaceful: " << relaxedCount << endl;
cout << "Safe & Satisfied: " << safeCount << endl;
cout << "Urgency: " << urgencyCount << endl;

size_t pos2 = book2.find_first_of(delimiters);
pos2 != string::npos;


	for(int i=0; i<book2.length(); i++)
	{

		size_t pos2 = book2.find_first_of(delimiters);

		book2sub = book2.substr(0,pos2);
		book2sub = stemString(book2sub);
		
		for(int j=0; j<anger.size(); j++)
		{
			angerStem=stemString(anger[j]);
		
				if(book2sub == angerStem)
				{

					angercount2++;

				}
		
		}
		
		for(int j=0; j<helplessness.size(); j++)
		{
			helplessStem=stemString(helplessness[j]);
		
				if(book2sub == helplessStem)
				{

					helplessCount2++;

				}
		
		}
	
		for(int j=0; j<happy.size(); j++)
		{
			happyStem=stemString(happy[j]);
		
				if(book2sub == happyStem)
				{

					happyCount2++;

				}
		
		}
		
		for(int j=0; j<inspired.size(); j++)
		{
			inspiredStem=stemString(inspired[j]);
		
				if(book2sub == inspiredStem)
				{

					inspiredCount2++;

				}
		
		}
	
		for(int j=0; j<relaxed.size(); j++)
		{
			relaxedStem=stemString(relaxed[j]);
		
				if(book2sub == relaxedStem)
				{

					relaxedCount2++;

				}
		
		}
		
		for(int j=0; j<safe.size(); j++)
		{
			safeStem=stemString(safe[j]);
		
				if(book2sub == safeStem)
				{

					safeCount2++;

				}
		
		}
	
		for(int j=0; j<urgency.size(); j++)
		{
			urgencyStem=stemString(urgency[j]);
		
				if(book2sub == urgencyStem)
				{

					urgencyCount2++;

				}
		
		}
	
	book2=book2.erase(0 , pos2 + 1);



}	
	
cout << "Emotion for 'Little men': " << endl;
cout << "Anger: " << angercount2 << endl;	
cout << "Confusion & Helplessness: " << helplessCount2 << endl;
cout << "Happy & Alive: " << happyCount2 << endl;
cout << "Inspired: " << inspiredCount2 << endl;
cout << "Relaxed & Peaceful: " << relaxedCount2 << endl;
cout << "Safe & Satisfied: " << safeCount2 << endl;
cout << "Urgency: " << urgencyCount2 << endl;

}
