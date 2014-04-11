#include "ComputerPlayer.h"

namespace Games
{
	ComputerPlayer::ComputerPlayer(void)
	{
	}

	bool ComputerPlayer::move()
	{
		return this->strategy->move();
	}

	void ComputerPlayer::setLevel(int s)
	{
		switch(s)
		{
		case Games::EASY:
			{
				this->strategy=new Easy();
				break;
			}
		case Games::MEDIUM:
			{
				this->strategy=new Medium();
				break;
			}
		case Games::DIFFICULT:
			{
				this->strategy=new Difficult();
				break;
			}
		}
	}

	ComputerPlayer::~ComputerPlayer(void)
	{
	}
}