#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

// a - Hearts
// b - Diamonds
// ñ - Clubs
// d - Spades
// 11 - Jack
// 12 - queen
// 13 - King
// 14 - ace
// push enter for make step

void shuffle(char *card_deck[]);
void set_players_card(char *player1[], char *player2[], char *card_deck[]);
int compare(char *player1_card, char *player2_card);
void change_player_card(char *player1[], char *player2[], int result, int *amount_card_player1, int *amount_card_player2);


int main()
{
	int *amount_card_player1 = new int(17);
	int	*amount_card_player2 = new int(17);

	char *card_deck[36] =
	{ { "6a" },{ "6b" },{ "6c" },{ "6d" },
	{ "7a" },{ "7b" },{ "7c" },{ "7d" },
	{ "8a" },{ "8b" },{ "8c" },{ "8d" },
	{ "9a" },{ "9b" },{ "9c" },{ "9d" },
	{ "10a" },{ "10b" },{ "10c" },{ "10d" },
	{ "11a" },{ "11b" },{ "11c" },{ "11d" },
	{ "12a" },{ "12b" },{ "12c" },{ "12d" },
	{ "13a" },{ "13b" },{ "13c" },{ "13d" },
	{ "14a" },{ "14b" },{ "14c" },{ "14d" } };

	//shuffle(card_deck);

	char *player1[36];
	char *player2[36];

	set_players_card(player1, player2, card_deck);

	
	while (true)
	{
		cout << "Player 1 = " << (*amount_card_player1) + 1 <<  '\t' << "Player 2 = " << (*amount_card_player2) + 1 << endl;
		cout << "card = " << player1[*amount_card_player1] << '\t' << "card = " << player2[*amount_card_player2] << endl;
		cin.get();
		change_player_card(player1, player2,
			compare(player1[*amount_card_player1], player2[*amount_card_player2]),
			amount_card_player1, amount_card_player2);
	}

	delete amount_card_player1, amount_card_player2;
}



void change_player_card(char *player1[], char *player2[], int result, int *amount_card_player1, int *amount_card_player2)
{
	char *temp_player1_card;
	char *temp_player2_card;
	static int count = 0;

	if (result == 0)
	{
		temp_player1_card = player1[*amount_card_player1];
		temp_player2_card = player2[*amount_card_player2];

		for (int i = (*amount_card_player1); i > 0; i--)
			swap(player1[i], player1[i - 1]);

		for (int i = (*amount_card_player2); i > 0; i--)
			swap(player2[i], player2[i - 1]);

		player1[0] = temp_player1_card;
		player2[0] = temp_player2_card;
		count++;
		return;
	}

	else if (result > 0)
	{
			temp_player1_card = player1[(*amount_card_player1)];
			temp_player2_card = player2[(*amount_card_player2)];
			for (int j = 0; j < 2; j++)
				for (int jj = (*amount_card_player1) + j + 1; jj > 0; jj--)
					swap(player1[jj], player1[jj - 1]);

			player1[(*amount_card_player1) + 2] = '\0';
			player2[*amount_card_player2] = '\0';

			player1[0] = temp_player2_card;
			player1[1] = temp_player1_card;

			(*amount_card_player1)++;
			(*amount_card_player2)--;

			while (count)
			{
				(*amount_card_player1)++;
				for (int i = (*amount_card_player1); i > 0; i--)
					swap(player1[i], player1[i - 1]);

				player1[0] = player2[0];

				for (int i = 0; i < (*amount_card_player2); i++)
					swap(player2[i], player2[i + 1]);
				(*amount_card_player2)--;
				count--;
			}
	}

	else if (result < 0)
	{
			temp_player1_card = player1[(*amount_card_player1)];
			temp_player2_card = player2[(*amount_card_player2)];

			for (int j = 0; j < 2; j++)
				for (int jj = (*amount_card_player2) + j + 1; jj > 0; jj--)
					swap(player2[jj], player2[jj - 1]);

			player2[(*amount_card_player2) + 2] = '\0';
			player1[*amount_card_player1] = '\0';

			player2[0] = temp_player2_card;
			player2[1] = temp_player1_card;

			(*amount_card_player1)--;
			(*amount_card_player2)++;

			while (count)
			{
				(*amount_card_player2)++;
				for (int i = (*amount_card_player2); i > 0; i--)
					swap(player2[i], player2[i - 1]);

				player2[0] = player1[0];

				for (int i = 0; i < (*amount_card_player1); i++)
					swap(player1[i], player1[i + 1]);
				(*amount_card_player1)--;
				count--;
			}
	}
	

	if ((*amount_card_player1) < 0)
	{
		cout << "Player 2 Win!";
		exit(-1);
	}
	else if ((*amount_card_player2) < 0)
	{
		cout << "Player 1 Win!";
		exit(-1);
	}


	count = 0;
}

int compare(char *player1_card, char *player2_card)
{
	char value_card[3];
	for (int i = 0; i< strlen(player1_card) - 1; i++)
		value_card[i] = player1_card[i];

	value_card[strlen(player1_card) - 1] = '\0';

	int player1_value_card = atoi(value_card);

	for (int i = 0; i< strlen(player2_card) - 1; i++)
		value_card[i] = player2_card[i];

	value_card[strlen(player2_card) - 1] = '\0';

	int player2_value_card = atoi(value_card);

	if (player1_value_card == 6 && player2_value_card == 14)
		return 1;

	else if (player1_value_card == 14 && player2_value_card == 6)
		return -1;

	else if (player1_value_card < player2_value_card)
		return -1;

	else if (player1_value_card > player2_value_card)
		return 1;

	else if (player1_value_card == player2_value_card)
		return 0;

	return 99999;

}

void shuffle(char *card_deck[])
{
	srand(time(0));
	for (int i = 0; i < 36; i++)
		swap(card_deck[0 + rand() % 36], card_deck[0 + rand() % 36]);
}

void set_players_card(char *player1[], char *player2[], char *card_deck[])
{
	for (int i = 0; i < 18; i++)
		player1[i] = card_deck[i];

	for (int i = 18; i < 36; i++)
		player2[i - 18] = card_deck[i];
}