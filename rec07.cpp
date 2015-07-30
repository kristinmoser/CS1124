/*
name: Kristin Moser
rec07.cpp
username: km3322

*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Instrument{
public:
	virtual void makeSound()const = 0;
	virtual void play() const = 0;

private:

};

class Brass: public Instrument{
public:
	Brass(const unsigned& mouthpieceSize) : size(mouthpieceSize){}
	virtual void makeSound()const = 0;
private:
	unsigned size;

};

void Brass::makeSound()const {
	cout << "To make a sound... blow on a mouthpiece of size " << size << endl;
}

class String: public Instrument{
public:
	String(const unsigned& bowPitch) : bowPitch(bowPitch){}
	virtual void makeSound() const = 0;
private:
	unsigned bowPitch;
};

void String::makeSound()const{
	cout << "To make a sound... bow a string with pitch " << bowPitch << endl;
}

class Percussion : public Instrument{
public:
	virtual void makeSound() const = 0;
private:

};

void Percussion::makeSound()const{
	cout << "To make a sound... hit me!" << endl;

}

class Trumpet : public Brass{
public:
	Trumpet(const unsigned& size) : Brass(size){}
	void makeSound()const{
		cout << "Trumpet" << endl;
		Brass::makeSound();
	}
	void play()const{
		cout << "Toot";
	}
private:

};

class Trombone : public Brass{
public:
	Trombone(const unsigned& size) : Brass(size){}
	void makeSound()const{
		cout << "Trombone" << endl;
		Brass::makeSound();
	}
	void play()const{
		cout << "Blat";
	}
private:

};

class Violin : public String {
public:
	Violin(const unsigned& bowPitch) : String(bowPitch){}
	void makeSound()const{
		cout << "Violin" << endl;
		String::makeSound();
	}
	void play()const{
		cout << "Screech";
	}
private:

};
class Cello : public String{
public:
	Cello(const unsigned& bowPitch) : String(bowPitch){}
	void makeSound()const{
		cout << "Cello" << endl;
		String::makeSound();
	}
	void play()const{
		cout << "Squawk";
	}
private:

};


class Drum : public Percussion{
public:
	void makeSound() const{
		cout << "Drums" << endl;
		Percussion::makeSound();
	}
	void play()const{
		cout << "Boom";
	}
private:

};
class Cymbal : public Percussion{
public:
	void makeSound() const{
		cout << "Cymbal" << endl;
		Percussion::makeSound();
	}
	void play()const{
		cout << "Crash";
	}
private:

};

class Musician {
public:
	Musician() : instr(NULL) {}
	void acceptInstr(Instrument & i) { instr = &i; }
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if (instr)
			instr->makeSound();
		else
			cerr << "have no instr\n";
	}
	void play()const{
		if (instr != nullptr){
			instr->play();
		}
		else{
			cout << "";
		}
	}
private:
	Instrument* instr;
};

class MILL{
public:
	Instrument* loanOut(){
		for (size_t i = 0; i < vecInstr.size(); ++i){
			if (vecInstr[i] != nullptr){
				Instrument* temp = vecInstr[i];
				vecInstr[i] = nullptr;
				return temp;
			}
		}
		return nullptr;
	}
	void receiveInstr(Instrument& instr){
		instr.makeSound();
		for (size_t i = 0; i < vecInstr.size(); ++i){
			if (vecInstr[i] == nullptr){
				vecInstr[i] = &instr;
				return;
			}
		}
		vecInstr.push_back(&instr);
	}
	void dailyTestPlay()const{
		for (size_t i = 0; i < vecInstr.size(); ++i){
			if (vecInstr[i] != nullptr){
				vecInstr[i]->makeSound();
			}
			else{
				cout << "";
			}
		}
	}

private:
	vector<Instrument*> vecInstr;
};

/*------------------------------PART TWO----------------------------------*/

class Orch{
public:
	void addPlayer(Musician& musician){
		vecMusicians.push_back(&musician);
	}
	
	void play() const{
		for (size_t i = 0; i < vecMusicians.size(); ++i){
			vecMusicians[i]->play();
		}
	}

private:
	vector<Musician*> vecMusicians;
};
int main(){

Drum drum;
Cello cello(673);
Cymbal cymbal;
Trombone tbone(4);
Trumpet trpt(12);
Violin violin(567);

MILL mill;
mill.receiveInstr(trpt);
mill.receiveInstr(violin);
mill.receiveInstr(tbone);
mill.receiveInstr(drum);
mill.receiveInstr(cello);
mill.receiveInstr(cymbal);

Musician bob;
Musician sue;
Musician mary;
Musician ralph;
Musician jody;
Musician morgan;

Orch orch;



// THE SCENARIO

//Bob joins the orchestra without an instrument.
orch.addPlayer(bob);

//The orchestra performs
cout << "\norch performs\n";
orch.play();

//Sue gets an instrument from the MIL2 and joins the orchestra.
sue.acceptInstr(*mill.loanOut());
orch.addPlayer(sue);

//Ralph gets an instrument from the MIL2.
ralph.acceptInstr(*mill.loanOut());

//Mary gets an instrument from the MIL2 and joins the orchestra.
mary.acceptInstr(*mill.loanOut());
orch.addPlayer(mary);

//Ralph returns his instrument to the MIL2.
mill.receiveInstr(*ralph.giveBackInstr());

//Jody gets an instrument from the MIL2 and joins the orchestra.
jody.acceptInstr(*mill.loanOut());
orch.addPlayer(jody);

// morgan gets an instrument from the MIL2
morgan.acceptInstr(*mill.loanOut());

//The orchestra performs.
cout << "\norch performs\n";
orch.play();

//Ralph joins the orchestra.
orch.addPlayer(ralph);

//The orchestra performs.
cout << "\norch performs\n";
orch.play();

// bob gets an instrument from the MIL2
bob.acceptInstr(*mill.loanOut());

// ralph gets an instrument from the MIL2
ralph.acceptInstr(*mill.loanOut());

//The orchestra performs.
cout << "\norch performs\n";
orch.play();

//Morgan joins the orchestra.
orch.addPlayer(morgan);

//The orchestra performs.
cout << "\norch performs\n";
orch.play();

system("pause");

}
