#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <iterator>
#include <map>
using namespace std;

//Generic Linked List Declaration
template <typename Type>
class ListNode {
public:
    Type data;
    ListNode* next;

};
//LinkedList data-type declaration
template <typename Type>
class LinkedList {
public:
    ListNode<Type>* start; // special variable which stores address of the head node.
    ListNode<Type>* last; // special variable which stores address of the last node.
    ListNode<Type>* PredLoc_; //to be used by Search(value) method to store address of logical predecessor of value in a list.
    ListNode<Type>* Loc_; //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.
    int length;
    //Creating an empty Linked List
    LinkedList() {
        start = NULL;
        last = NULL;
        PredLoc_ = NULL;
        Loc_ = NULL;
        length = 0;
    }
    //returns the length of the list
    int getLength() const {
        return length;
    }


    // checks whether the list is empty or not. Returns true if empty and false otherwise.
    bool isEmpty() {
        return start == NULL;
    }
    // takes input from a user and inserts it at the front of a list
    void InsertAtFront(Type value) {
        ListNode<Type>* newNode = new ListNode<Type>();
        newNode->data = value;
        if (isEmpty()) {
            start = newNode;
            last = newNode;
            length++;

        }
        else {
            newNode->next = start;
            start = newNode;
            length++;
        }
    }
    // takes input from a user and inserts it at the tail end of a list
    void InsertAtEnd(Type value) {
        ListNode<Type>* newNode = new ListNode<Type>();
        newNode->data = value;
        if (isEmpty()) {
            start = newNode;
            last = newNode;
            length++;
        }
        else {
            last->next = newNode;
            last = newNode;
            length++;
        }
    }
    //prints the list
    void PrintList() {
        if (!isEmpty()) {
            ListNode<Type>* temp = start;
            while (temp != NULL) {
                cout << temp->data << " | ";
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "The list is Empty!" << endl;
        }

    }
    //searches a value in list
    bool SearchValue(Type value) {
        Loc_ = start;
        PredLoc_ = NULL;
        if (isEmpty()) {
            return false;
        }
        while (Loc_ != NULL) {
            if (Loc_->data.compare(value) == 0)
            {
                return true;
            }
            Loc_ = Loc_->next;
        };
        //as value is not found so set loc equal to null.
        if (Loc_ != NULL && Loc_->data.compare(value) != 0) {
            return false;
        }
    }
    void InsertSorted(Type value) {

        Search(value);
        if (Loc_ != NULL) {
            cout << "Value already exists" << endl;

        }
        else {
            if (PredLoc_ == NULL) {
                InsertAtFront(value);

            }
            else {
                ListNode<Type>* newNode = new ListNode<Type>();
                length++;
                newNode->data = value;
                newNode->next = PredLoc_->next;
                if (PredLoc_ == last) {
                    last = newNode;
                }
                PredLoc_->next = newNode;
            }
        }

    }
    // searches value and then  deletes it if found.
    void Delete(Type value) {
        if (isEmpty()) { return; }
        Search(value);
        if (Loc_ != NULL) {
            if (PredLoc_ == NULL) {
                if (Loc_ == last) {
                    start = NULL;
                    last = NULL;
                    delete Loc_;
                    length--;

                }
                else {
                    start = start->next;
                    delete Loc_;
                    length--;
                }
            }
            else {
                if (Loc_ == last) {
                    last = PredLoc_;
                    PredLoc_->next = Loc_->next;
                    delete Loc_;
                    length--;
                }
                else {
                    //update link using ploc
                    PredLoc_->next = Loc_->next;
                    //finally free memory using delete command.
                    delete Loc_;
                    length--;
                }
            }
        }
        else {
            cout << "Value not found. Deletion not possible." << endl;
        }
    }
    void DestroyList() {
        while (start != NULL) {
            ListNode<Type>* temp = start;
            start = start->next;
            delete temp;
        }
        last = NULL;
        length = 0;
    }



};//end of LinkedList declaration


//Movie Class Declaration
class Movie {

    //Definition of each Field
    string MovieTitle;
    LinkedList<string> genres;
    int TitleYear;
    float IMDB_Score;
    string DirectorName;
    unsigned short int  DirectorFbLikes;
    unsigned short int num_critic_for_reviews;
    unsigned short int duration;
    string Actor1Name;
    unsigned short int Actor1FbLikes;
    string Actor2Name;
    unsigned short int Actor2FbLikes;
    string Actor3Name;
    unsigned short int Actor3FbLikes;
    int gross;
    int num_voted_users;
    int cast_total_facebook_likes;
    unsigned short int facenumber_in_poster;
    LinkedList<string> plot_keywords;
    string movie_imdb_link;
    int num_user_for_reviews;
    string language;
    string country;
    string ContentRating;
    int budget;
    float AspectRatio;
    int MovieFbLikes;
    string color;

    //setters for each field
public:
    void setMovieTitle(const string& movieTitle) {
        MovieTitle = movieTitle;
    }

    void setGenres(const LinkedList<string>& genres) {
        Movie::genres = genres;
    }

    void setTitleYear(int titleYear) {
        TitleYear = titleYear;
    }

    void setImdbScore(float imdbScore) {
        IMDB_Score = imdbScore;
    }

    void setDirectorName(const string& directorName) {
        DirectorName = directorName;
    }

    void setDirectorFbLikes(unsigned short directorFbLikes) {
        DirectorFbLikes = directorFbLikes;
    }

    void setNumCriticForReviews(unsigned short numCriticForReviews) {
        num_critic_for_reviews = numCriticForReviews;
    }

    void setDuration(unsigned short duration) {
        Movie::duration = duration;
    }

    void setActor1Name(const string& actor1Name) {
        Actor1Name = actor1Name;
    }

    void setActor1FbLikes(unsigned short actor1FbLikes) {
        Actor1FbLikes = actor1FbLikes;
    }

    void setActor2Name(const string& actor2Name) {
        Actor2Name = actor2Name;
    }

    void setActor2FbLikes(unsigned short actor2FbLikes) {
        Actor2FbLikes = actor2FbLikes;
    }

    void setActor3Name(const string& actor3Name) {
        Actor3Name = actor3Name;
    }

    void setActor3FbLikes(unsigned short actor3FbLikes) {
        Actor3FbLikes = actor3FbLikes;
    }

    void setGross(int gross) {
        Movie::gross = gross;
    }

    void setNumVotedUsers(int numVotedUsers) {
        num_voted_users = numVotedUsers;
    }

    void setCastTotalFacebookLikes(int castTotalFacebookLikes) {
        cast_total_facebook_likes = castTotalFacebookLikes;
    }

    void setFacenumberInPoster(unsigned short facenumberInPoster) {
        facenumber_in_poster = facenumberInPoster;
    }

    void setPlotKeywords(const LinkedList<string>& plotKeywords) {
        plot_keywords = plotKeywords;
    }

    void setMovieImdbLink(const string& movieImdbLink) {
        movie_imdb_link = movieImdbLink;
    }

    void setNumUserForReviews(int numUserForReviews) {
        num_user_for_reviews = numUserForReviews;
    }

    void setLanguage(const string& language) {
        Movie::language = language;
    }

    void setCountry(const string& country) {
        Movie::country = country;
    }

    void setContentRating(const string& contentRating) {
        ContentRating = contentRating;
    }

    void setBudget(int budget) {
        Movie::budget = budget;
    }

    void setAspectRatio(float aspectRatio) {
        AspectRatio = aspectRatio;
    }

    void setMovieFbLikes(int movieFbLikes) {
        MovieFbLikes = movieFbLikes;
    }

    void setColor(string color) {
        Movie::color = color;
    }


    //-----------------Getters for each field-----------------------------

    const string& getMovieTitle() const {
        return MovieTitle;
    }

    const LinkedList<string>& getGenres() const {
        return genres;
    }

    int getTitleYear() const {
        return TitleYear;
    }

    float getImdbScore() const {
        return IMDB_Score;
    }

    const string& getDirectorName() const {
        return DirectorName;
    }

    unsigned short getDirectorFbLikes() const {
        return DirectorFbLikes;
    }

    unsigned short getNumCriticForReviews() const {
        return num_critic_for_reviews;
    }

    unsigned short getDuration() const {
        return duration;
    }

    const string& getActor1Name() const {
        return Actor1Name;
    }

    unsigned short getActor1FbLikes() const {
        return Actor1FbLikes;
    }

    const string& getActor2Name() const {
        return Actor2Name;
    }

    unsigned short getActor2FbLikes() const {
        return Actor2FbLikes;
    }

    const string& getActor3Name() const {
        return Actor3Name;
    }

    unsigned short getActor3FbLikes() const {
        return Actor3FbLikes;
    }

    int getGross() const {
        return gross;
    }

    int getNumVotedUsers() const {
        return num_voted_users;
    }

    int getCastTotalFacebookLikes() const {
        return cast_total_facebook_likes;
    }

    unsigned short getFacenumberInPoster() const {
        return facenumber_in_poster;
    }

    const LinkedList<string>& getPlotKeywords() const {
        return plot_keywords;
    }

    const string& getMovieImdbLink() const {
        return movie_imdb_link;
    }

    int getNumUserForReviews() const {
        return num_user_for_reviews;
    }

    const string& getLanguage() const {
        return language;
    }

    const string& getCountry() const {
        return country;
    }

    const string& getContentRating() const {
        return ContentRating;
    }

    int getBudget() const {
        return budget;
    }

    float getAspectRatio() const {
        return AspectRatio;
    }

    int getMovieFbLikes() const {
        return MovieFbLikes;
    }

    const string& getColor() const {
        return color;
    }


};
//Director Node Declaration to iterate through Director List
class DirectorNode {
public:
    string DirectorName; //storing director name
    LinkedList<string> MoviesDirected; //returns the list of movies directed by the given director
    int DirectorFbLikes; //store FB likes for the current director
    DirectorNode* next;
};
//Director List Declaration
class DirectorList {
public:
    //getter for movies directed
    LinkedList<string> getMoviesDirected(string name) {
        Search(name);
        return Loc_->MoviesDirected;

    };
    //getter for FB likes
    int getFbLikes(string name) {
        Search(name);
        return Loc_->DirectorFbLikes;
    }

    //Initializing empty list
    DirectorNode* start = NULL;
    DirectorNode* last = NULL;
    DirectorNode* Loc_ = NULL;
    bool found = false;

    //search function to search specific node (pass director name in value)
    void Search(string value) {
        Loc_ = start; //Local variables to iterate
        found = false; //found boolean to check if the value is found
        if (start == NULL) {
            found = false;
            return;
        }

        while (Loc_ != NULL) {
            if (Loc_->DirectorName.compare(value) == 0)
            {
                found = true;
                break;
            }
            Loc_ = Loc_->next;
        };
        //as value is not found so set loc equal to null.
        if (Loc_ != NULL && Loc_->DirectorName.compare(value) != 0) {
            found = false;
            Loc_ = NULL;
        }
    }


public:
    //Inserts node at the end of the list
    void Insert(string name, string movieDirected, int DirectorFbLikes) {
        Search(name);
        if (!found) {
            DirectorNode* newNode = new DirectorNode();
            newNode->DirectorName = name;
            newNode->MoviesDirected.InsertAtEnd(movieDirected);
            newNode->DirectorFbLikes = DirectorFbLikes;
            if (start == NULL) {
                start = newNode;
                last = newNode;
            }
            else {
                last->next = newNode;
                last = newNode;
            }
        }
        //Updates node(director) if already present
        else {
            Loc_->MoviesDirected.InsertAtEnd(movieDirected);
            Loc_->DirectorFbLikes = Loc_->DirectorFbLikes + DirectorFbLikes;
        }

    }
    //prints the list the directors
    void showDirectors() {
        if (start != NULL) {
            DirectorNode* temp = start;
            while (temp != NULL) {
                cout << temp->DirectorName << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "The list is Empty!" << endl;
        }

    }


};
//Declaration of actor node
class ActorNode {
public:
    string ActorName; //stores actor name
    LinkedList<string> MoviesActedIn; //stores the list of movies the actor worked in
    int ActorFbLikes; //stores FB likes of the specific actor
    ActorNode* next;
};

class ActorList {
public:
    LinkedList<string> getMoviesActedIn(string name) {
        Search(name);
        return Loc_->MoviesActedIn;

    };
    int getFbLikes(string name) {
        Search(name);
        return Loc_->ActorFbLikes;
    }
    ActorNode* start = NULL;
    ActorNode* last = NULL;
    ActorNode* Loc_ = NULL;
    bool found = false;

    //Search actor in list by name, returns true if found
    void Search(string name) {
        Loc_ = start;
        found = false;
        if (start == NULL) {
            found = false;
            return;
        }

        while (Loc_ != NULL) {
            if (Loc_->ActorName.compare(name) == 0)
            {
                found = true;
                break;
            }
            Loc_ = Loc_->next;
        };
        //as value is not found so set loc equal to null.
        if (Loc_ != NULL && Loc_->ActorName.compare(name) != 0) {
            found = false;
            Loc_ = NULL;
        }
    }


public:
    //Function to add actor to actorlist
    void Insert(string name, string movieActedIn, int ActorFbLikes) {
        Search(name);
        //if actor does not exist
        if (!found) {
            ActorNode* newNode = new ActorNode();
            newNode->ActorName = name;
            newNode->MoviesActedIn.InsertAtEnd(movieActedIn);
            newNode->ActorFbLikes = ActorFbLikes;
            if (start == NULL) {
                start = newNode;
                last = newNode;
            }
            else {
                last->next = newNode;
                last = newNode;
            }
        }
        //if actor already exists, just update the movies acted-in list
        else {
            Loc_->MoviesActedIn.InsertAtEnd(movieActedIn);
            Loc_->ActorFbLikes = Loc_->ActorFbLikes + ActorFbLikes;
        }

    }
    //Print the list of Actors
    void showActors() {
        if (start != NULL) {
            ActorNode* temp = start;
            while (temp != NULL) {
                cout << temp->ActorName << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "The list is Empty!" << endl;
        }

    }

};

//Movie Class Declaration
class MovieNode {
public:
    Movie data; //store data(title,director,actor....etc) of movie
    MovieNode* next; //iterative variable
};
//MovieList Class Declaration
class MovieList {

public:
    //Default Constructor
    MovieList() {

    }
    //Copy Constructor
    MovieList(MovieList const& list) {
    }

    DirectorList directorList; //initialize a director list to insert directors in it
    ActorList actorList; //initialize an actor list to insert actors in it

    MovieNode* start = NULL;
    MovieNode* last = NULL;
    // takes input from a user and inserts it at the tail end of a list
    void InsertMovie(Movie value) {
        MovieNode* newNode = new MovieNode();
        newNode->data = value;
        if (start == NULL) {
            start = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }
    //Prints movies titles
    void showMovies() {
        if (start != NULL) {
            MovieNode* temp = start;
            while (temp != NULL) {
                cout << temp->data.getMovieTitle() << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            cout << "The list is Empty!" << endl;
        }

    }

public:
    //Parser
    ifstream myFileStream; //initialize a file stream
    void SetFile(char* filename) //select file to parse
    {
        myFileStream.open(filename); //open selected file
        if (myFileStream.fail()) //Show error message if the file failed to open
            cout << "File does not exist" << endl;
        string line;
        while (getline(myFileStream, line)) { //parse each line separately
            stringstream ss(line);
            Movie m;
            string tempString;
            string tempString2;
            string tempString3;
            string x;
            //parse each string to right field
            getline(ss, tempString, '#');
            if (tempString[0] == '"') {
                tempString.erase(0, 1);
                getline(ss, x, ',');
            }
            else { getline(ss, x, ','); }
            m.setMovieTitle(tempString);
            getline(ss, tempString, ',');
            stringstream tempss(tempString);
            LinkedList<string> genre;
            while (getline(tempss, tempString2, '|')) {
                genre.InsertAtEnd(tempString2);
            }
            m.setGenres(genre);
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setTitleYear(-1);
            }
            else { m.setTitleYear(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setImdbScore(-1.0);
            }
            else { m.setImdbScore(stod(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setDirectorName("-1");
            }
            else { m.setDirectorName(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setDirectorFbLikes(-1);
            }
            else { m.setDirectorFbLikes(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setNumCriticForReviews(-1);
            }
            else { m.setNumCriticForReviews(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setDuration(-1);
            }
            else { m.setDuration(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setActor1Name("-1");
            }
            else { m.setActor1Name(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setActor1FbLikes(-1);
            }
            else { m.setActor1FbLikes(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setActor2Name("-1");
            }
            else { m.setActor2Name(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setActor2FbLikes(-1);
            }
            else { m.setActor2FbLikes(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setActor3Name("-1");
            }
            else { m.setActor3Name(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setActor3FbLikes(-1);
            }
            else { m.setActor3FbLikes(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setGross(-1);
            }
            else { m.setGross(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setNumVotedUsers(-1);
            }
            else { m.setNumVotedUsers(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setCastTotalFacebookLikes(-1);
            }
            else { m.setCastTotalFacebookLikes(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setFacenumberInPoster(-1);
            }
            else { m.setFacenumberInPoster(stol(tempString)); }
            getline(ss, tempString, ',');
            stringstream tempss2(tempString);
            LinkedList<string> PlotKeywords;
            while (getline(tempss, tempString2, '|')) {
                PlotKeywords.InsertAtEnd(tempString2);
            }
            m.setPlotKeywords(PlotKeywords);
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setMovieImdbLink("-1");
            }
            else { m.setMovieImdbLink(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setNumUserForReviews(-1);
            }
            else { m.setNumUserForReviews(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setLanguage("-1");
            }
            else { m.setLanguage(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setCountry("-1");
            }
            else { m.setCountry(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setContentRating("-1");
            }
            else { m.setContentRating(tempString); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setBudget(-1);
            }
            else { m.setBudget(stoll(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setAspectRatio(-1.0);
            }
            else { m.setAspectRatio(stof(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setMovieFbLikes(-1.0);
            }
            else { m.setMovieFbLikes(stol(tempString)); }
            getline(ss, tempString, ',');
            if (tempString.empty()) {
                m.setColor("-1");
            }
            else { m.setColor(tempString); }
            InsertMovie(m); //insert each movie parsed into movielist
            directorList.Insert(m.getDirectorName(), m.getMovieTitle(), m.getDirectorFbLikes()); //insert parsed director into directorlist
            actorList.Insert(m.getActor1Name(), m.getMovieTitle(), m.getActor1FbLikes()); //insert parsed actor into actorlist
            actorList.Insert(m.getActor2Name(), m.getMovieTitle(), m.getActor2FbLikes()); //insert parsed actor2 into actorlist
            actorList.Insert(m.getActor3Name(), m.getMovieTitle(), m.getActor3FbLikes()); //insert parsed actor3 into actorlist

        }
    }



};
//-----------Functions to sort movies by year---------------
//---------Big-O-Complexity O(n^2) n squared
/*Function to swap the nodes */
ListNode<MovieNode>* swap(ListNode<MovieNode>* ptr1, ListNode<MovieNode>* ptr2)
{
    ListNode<MovieNode>* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
/* Function to sort the list */
void bubbleSort(ListNode<MovieNode>** head, int count)
{
    ListNode<MovieNode>** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            ListNode<MovieNode>* p1 = *h;
            ListNode<MovieNode>* p2 = p1->next;

            if (p1->data.data.getTitleYear() > p2->data.data.getTitleYear())
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
//-----------End of Functions to sort movies by year---------------

MovieNode* SearchMovie(string title, MovieList& movieList); //Forward Declaration

//-----------Task1---------------------------------------
void SearchActor(string name, MovieList& movieList) {
    movieList.actorList.Search(name); //search the actor first
    cout << "Name: " << movieList.actorList.Loc_->ActorName << endl; //print his name
    cout << "Count of movies acted in: " << movieList.actorList.getMoviesActedIn(name).getLength() << endl; //print number of movies he acted in
    ListNode<string>* temp = movieList.actorList.getMoviesActedIn(name).start;
    LinkedList<MovieNode> movies; //create temp list to store the movies the searched actor worked in
    while (temp != NULL) {
        movies.InsertAtEnd(*SearchMovie(temp->data, movieList));
        temp = temp->next;
    }
    bubbleSort(&movies.start, movies.getLength()); //sort the list with ascending year
    ListNode<MovieNode>* temp2 = movies.start;
    while (temp2 != NULL) {
        cout << temp2->data.data.getMovieTitle() << " | " << temp2->data.data.getTitleYear() << endl;
        temp2 = temp2->next;
    }

}

//---------------Task2--------------------------------
void SearchCoActor(string name, MovieList& movieList) {
    ListNode<string>* temp = movieList.actorList.getMoviesActedIn(name).start; //get the movie titles worked bu the actor
    LinkedList<MovieNode> movies;
    while (temp != NULL) {
        movies.InsertAtEnd(*SearchMovie(temp->data, movieList));
        temp = temp->next;
    }
    ListNode<MovieNode>* temp2 = movies.start;
    while (temp2 != NULL) {
        cout << "Movie Name: " << temp2->data.data.getMovieTitle() << endl;
        //if actor is actor1 print actor2 and actor3
        if (name.compare(temp2->data.data.getActor1Name()) == 0) {
            cout << "Co-Actors: " << temp2->data.data.getActor2Name() << "," << temp2->data.data.getActor3Name() << endl;
        }
        //if actor is actor2 print actor1 and actor3
        else if (name.compare(temp2->data.data.getActor2Name()) == 0) {
            cout << "Co-Actors: " << temp2->data.data.getActor1Name() << "," << temp2->data.data.getActor3Name() << endl;
        }
        //if actor is actor3 print actor1 and actor2
        else {
            cout << "Co-Actors: " << temp2->data.data.getActor1Name() << "," << temp2->data.data.getActor2Name() << endl;
        }
        temp2 = temp2->next;
    }
}

//--------Task3---------------------------
void SearchUniqueCoActor(string name, MovieList& movieList) {
    ListNode<string>* temp = movieList.actorList.getMoviesActedIn(name).start;
    LinkedList<MovieNode> movies;
    LinkedList<string> coActors; //create a new string linkedlist to store coacters
    LinkedList<string> MoviesCoActed;
    while (temp != NULL) {
        movies.InsertAtEnd(*SearchMovie(temp->data, movieList));
        temp = temp->next;
    }
    ListNode<MovieNode>* temp2 = movies.start;
    while (temp2 != NULL) {
        if (name.compare(temp2->data.data.getActor1Name()) == 0) {
            if (coActors.SearchValue(temp2->data.data.getActor2Name()) == 0) {
                coActors.InsertAtEnd(temp2->data.data.getActor2Name());
                MoviesCoActed.InsertAtEnd(temp2->data.data.getMovieTitle());
            }
            if (coActors.SearchValue(temp2->data.data.getActor3Name()) == 0) {
                coActors.InsertAtEnd(temp2->data.data.getActor3Name());
                MoviesCoActed.InsertAtEnd(temp2->data.data.getMovieTitle());
            }

        }
        else if (name.compare(temp2->data.data.getActor2Name()) == 0) {
            if (coActors.SearchValue(temp2->data.data.getActor1Name()) == 0) {
                coActors.InsertAtEnd(temp2->data.data.getActor1Name());
                MoviesCoActed.InsertAtEnd(temp2->data.data.getMovieTitle());

            }
            if (coActors.SearchValue(temp2->data.data.getActor3Name()) == 0) {
                coActors.InsertAtEnd(temp2->data.data.getActor3Name());
                MoviesCoActed.InsertAtEnd(temp2->data.data.getMovieTitle());
            }
        }
        else {
            if (coActors.SearchValue(temp2->data.data.getActor1Name()) == 0) {
                coActors.InsertAtEnd(temp2->data.data.getActor1Name());
                MoviesCoActed.InsertAtEnd(temp2->data.data.getMovieTitle());
            }
            if (coActors.SearchValue(temp2->data.data.getActor2Name()) == 0) {
                coActors.InsertAtEnd(temp2->data.data.getActor2Name());
                MoviesCoActed.InsertAtEnd(temp2->data.data.getMovieTitle());
            }
        }
        temp2 = temp2->next;
    }
    ListNode<string>* temp3 = MoviesCoActed.start;
    ListNode<string>* temp4 = coActors.start;
    while (temp4 != NULL) {
        cout << temp4->data << " | " << temp3->data << endl;
        temp3 = temp3->next;
        temp4 = temp4->next;

    }
}

//---------------Task4--------------------------------
void printCoActorOfCoActor(string name, MovieList& movieList) {
    ListNode<string>* temp = movieList.actorList.getMoviesActedIn(name).start; //get the movie titles worked bu the actor
    LinkedList<MovieNode> movies;
    string coactor1;
    string coactor2;

    while (temp != NULL) {
        movies.InsertAtEnd(*SearchMovie(temp->data, movieList));
        temp = temp->next;
    }
    ListNode<MovieNode>* temp2 = movies.start;
    while (temp2 != NULL) {

        cout << "\n------------------------------------------------------------------" << endl;
        cout << "\t\tMovie Name: " << temp2->data.data.getMovieTitle() << endl;
        cout << "------------------------------------------------------------------" << endl;

        //if actor is actor1 print actor2 and actor3
        if (name.compare(temp2->data.data.getActor1Name()) == 0) {

            coactor1 = temp2->data.data.getActor2Name();
            cout << "------------------------------------------------------------------" << endl;
            cout << "\t\tCoactor-1: " << coactor1 << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Co-Actors of " << coactor1 << " :-\n" << endl;
            SearchCoActor(coactor1, movieList);
            
            coactor2 = temp2->data.data.getActor3Name();
            cout << "\n------------------------------------------------------------------" << endl;
            cout << "\t\tCoactor-2: " << coactor2 << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Co-Actors of " << coactor2 << " :-\n" << endl;
            SearchCoActor(coactor2, movieList);
        }
        //if actor is actor2 print actor1 and actor3
        else if (name.compare(temp2->data.data.getActor2Name()) == 0) {
            coactor1 = temp2->data.data.getActor1Name();
            cout << "------------------------------------------------------------------" << endl;
            cout << "\t\tCoactor-1: " << coactor1 << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Co-Actors of " << coactor1 << " :-\n" << endl;
            SearchCoActor(coactor1, movieList);

            coactor2 = temp2->data.data.getActor3Name();
            cout << "\n------------------------------------------------------------------" << endl;
            cout << "\t\tCoactor-2: " << coactor2 << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Co-Actors of " << coactor2 << " :-\n" << endl;
            SearchCoActor(coactor2, movieList);
        }
        //if actor is actor3 print actor1 and actor2
        else {
            coactor1 = temp2->data.data.getActor1Name();
            cout << "------------------------------------------------------------------" << endl;
            cout << "\t\tCoactor-1: " << coactor1 << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Co-Actors of " << coactor1 << " :-\n" << endl;
            SearchCoActor(coactor1, movieList);

            coactor2 = temp2->data.data.getActor2Name();
            cout << "\n------------------------------------------------------------------" << endl;
            cout << "\t\tCoactor-2: " << coactor2 << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Co-Actors of " << coactor2 << " :-\n" << endl;
            SearchCoActor(coactor2, movieList);
        }
        temp2 = temp2->next;
    }
}


//---------------Task 5--------------------------------
void checkIfCoActor(string name1, string name2, MovieList& movieList) {
    ListNode<string>* temp = movieList.actorList.getMoviesActedIn(name1).start; //get the movie titles worked bu the actor
    LinkedList<MovieNode> movies;
    while (temp != NULL) {
        movies.InsertAtEnd(*SearchMovie(temp->data, movieList));
        temp = temp->next;
    }
    ListNode<MovieNode>* temp2 = movies.start;
    while (temp2 != NULL) {
        
        //if actor is actor1 print actor2 and actor3
        if (name1.compare(temp2->data.data.getActor1Name()) == 0) {
            if (name2.compare(temp2->data.data.getActor2Name()) == 0 || name2.compare(temp2->data.data.getActor3Name()) == 0  ) {
                cout << name1 << " and " << name2 << " are co-actors in movie \"" << temp2->data.data.getMovieTitle() << "\"." << endl;
            }
        }
        //if actor is actor2 print actor1 and actor3
        else if (name1.compare(temp2->data.data.getActor2Name()) == 0) {
            if (name2.compare(temp2->data.data.getActor1Name()) == 0 || name2.compare(temp2->data.data.getActor3Name()) == 0) {
                cout << name1 << " and " << name2 << " are co-actors in movie \"" << temp2->data.data.getMovieTitle() << "\"" << endl;
            }
        }
        //if actor is actor3 print actor1 and actor2
        else {
            if (name2.compare(temp2->data.data.getActor1Name()) == 0 || name2.compare(temp2->data.data.getActor2Name()) == 0) {
                cout << name1 << " and " << name2 << " are co-actors in movie \"" << temp2->data.data.getMovieTitle() << "\"" << endl;
            }
        }
        temp2 = temp2->next;
    }
}
//---------------Task6-------------------------------
void SearchDirector(string name, MovieList& movieList) {
    DirectorList d = movieList.directorList;
    d.getMoviesDirected(name).PrintList();
}

//-------------Task7----------------------------------------
//Print directors who have directed movies of a specific genre
bool SearchGenre(string genre, LinkedList<string> genreList) {
    ListNode<string>* Loc_ = genreList.start;
    bool found = false;
    if (genreList.start == NULL) {
        return found;
    }

    while (Loc_ != NULL) {
        if (Loc_->data.compare(genre) == 0)
        {
            found = true;
            return found;
        }
        Loc_ = Loc_->next;
    };
}
void PrintDirectorInGenre(string genre, MovieList& movieList) {
    MovieNode* temp = movieList.start;
    LinkedList<string> DirectorsInGenre;
    while (temp != NULL) {
        if (SearchGenre(genre, temp->data.getGenres())) {
            DirectorsInGenre.InsertAtEnd(temp->data.getDirectorName());
        }
        temp = temp->next;
    }
    DirectorsInGenre.PrintList();
}
//------End of Task7---------------------------------------------------------------------

//------------------Task8-----------------------------------
MovieNode* SearchMovie(string title, MovieList& movieList) {
    //Searches and stores the data in Loc_ of the given movie
    MovieNode* Loc_ = NULL;
    Loc_ = movieList.start;
    if (movieList.start == NULL) {
        return Loc_;
    }

    while (Loc_ != NULL) {
        if (Loc_->data.getMovieTitle().compare(title) == 0)
        {
            return Loc_;
        }
        Loc_ = Loc_->next;
    };
}


//------------Task9-----------------------------------
//Prints all movies in a given year
void SearchMovieInYear(int year, MovieList& movieList) {
    LinkedList<string> MovieTitles;
    MovieNode* temp = movieList.start;
    while (temp != NULL) {
        if (temp->data.getTitleYear() == year) {
            MovieTitles.InsertAtEnd(temp->data.getMovieTitle());
        }
        temp = temp->next;
    }
    MovieTitles.PrintList();
}
//--------------Task10---------------
//Prints the movies in ascending order
void PrintMoviesYearWise(MovieList& movieList) {
    string name;
    int year;
    LinkedList<MovieNode> movies;
    MovieNode* temp = movieList.start;
    while (temp != NULL) {
        movies.InsertAtEnd(*temp);
        temp = temp->next;
    }
    bubbleSort(&movies.start, movies.getLength());
    ListNode<MovieNode>* temp2 = movies.start;
    while (temp2 != NULL) {
        name = temp2->data.data.getMovieTitle();
        year = temp2->data.data.getTitleYear();
        if (year == -1) {
            cout << name << " | " << "NULL Field" << endl;
        }
        else {
            cout << name << " | " << year << endl;
        }
        temp2 = temp2->next;
    }
}


int main() {
    MovieList M = MovieList(MovieList());

    const char* p1 = "C:\\Users\\Awais\\Downloads\\DSA-Mini-Project\\DSA-Mini-Project\\DSA-mini-Project\\test.txt" ;
    char* p2;
    p2 = const_cast<char*>(p1);

    M.SetFile(p2);

    //SearchActor("CCH Pounder", M);

    SearchCoActor("Joel David Moore", M);
    cout << endl;
    //SearchUniqueCoActor("CCH Pounder", M);

    //SearchCoActor("CCH Pounder", M);

    printCoActorOfCoActor("CCH Pounder", M);
    //checkIfCoActor("CCH Pounder", "Jimmy Bennett", M);
    return 0;
}

