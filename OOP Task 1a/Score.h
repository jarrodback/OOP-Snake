#pragma once
class Score
{
private:
	int amount;
public:
	//Constructor
	Score();
	//Query
	int getAmount() const;
	//Update
	void updateAmount(int amt);
};

