#pragma once


struct Telegram
{
	int Sender;
	int Receiver;
	int Msg;
	Telegram() :Sender(-1), Receiver(-1), Msg(-1) {}
	Telegram(int sender, int receiver, int msg) :Sender(sender), Receiver(receiver), Msg(msg) {}
};