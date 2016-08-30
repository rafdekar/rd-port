#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
using namespace std;

class pudla
{	
public:
	vector < sf::Sprite > pudla_kontener;
	sf::Texture tekstura_pudla;
	sf::Sprite pudlo;
	void stworz_pudlo( int pudlo_x, int pudlo_y )
	{
		tekstura_pudla.loadFromFile( "Grafika/met.png" );
		pudlo.setTexture( tekstura_pudla );
		pudlo.setPosition( pudlo_x, pudlo_y );
		pudla_kontener.push_back( pudlo );
	}
};

class gwiazdy
{	
public:
	vector < sf::Sprite > gwiazdy_kontener;
	sf::Texture tekstura_gwiazdy;
	sf::Sprite gwiazda;
	void stworz_gwiazde( int gwiazda_x, int gwiazda_y )
	{
		tekstura_gwiazdy.loadFromFile( "Grafika/gw.png" );
		gwiazda.setTexture( tekstura_gwiazdy );
		gwiazda.setPosition( gwiazda_x, gwiazda_y );
		gwiazdy_kontener.push_back( gwiazda );
	}
};

class pociski
{
public:
	vector < sf::Sprite > pociski_kontener;
	sf::Texture tekstura_pocisku;
	sf::Sprite pocisk;
	void stworz_pocisk( int pocisk_x, int pocisk_y )
	{
		tekstura_pocisku.loadFromFile( "Grafika/pocisk.png" );
		pocisk.setTexture( tekstura_pocisku );
		pocisk.setPosition( pocisk_x + 12, pocisk_y - 4 );
		pociski_kontener.push_back( pocisk );
	}
};

class wybuchy
{
public:
	vector < sf::Sprite > wybuchy_kontener;
	sf::Texture tekstura_wybuchu;
	sf::Sprite wybuch;
	void stworz_wybuch( int wybuch_x, int wybuch_y )
	{
		tekstura_wybuchu.loadFromFile( "Grafika/wybuch_animacja.png", sf::IntRect( 0, 0, 149, 109 ) );
		wybuch.setTexture( tekstura_wybuchu );
		wybuch.setPosition( wybuch_x - 36, wybuch_y - 25 );
		wybuchy_kontener.push_back( wybuch );
	}
};

int main()
{
	sf::RenderWindow OknoAplikacji( sf::VideoMode( 640, 480, 32 ), "Space Fight" );
	OknoAplikacji.setFramerateLimit( 60 );

	sf::Texture tekstura_statku, tekstura_statku2, tekstura_statku3, tekstura_statku4;
	tekstura_statku.loadFromFile( "Grafika/statek5.png", sf::IntRect( 0, 0, 30, 78 ) );
	tekstura_statku2.loadFromFile( "Grafika/statek5.png", sf::IntRect( 30, 0, 30, 78 ) );
	tekstura_statku3.loadFromFile( "Grafika/statek5.png", sf::IntRect( 60, 0, 30, 78 ) );
	tekstura_statku4.loadFromFile( "Grafika/statek5.png", sf::IntRect( 90, 0, 30, 78 ) );

	sf::Sprite statek, pudlo;
	statek.setTexture( tekstura_statku );
	statek.setPosition( 225, 396 );

	bool shoot = false;

	pudla pudla_obiekt;
	pociski pociski_obiekt;
	gwiazdy gwiazdy_obiekt;

	sf::Clock clock;
	sf::Clock los;
	sf::Clock gw;
	sf::Clock statek_z;
	sf::Clock statek_w;

	sf::SoundBuffer strzal_buf, wybuch_buf;
	if ( !strzal_buf.loadFromFile( "Dzwieki/strzal.ogg" ) || !wybuch_buf.loadFromFile( "Dzwieki/wybuch.ogg" ) )
		return -1;
	sf::Sound strzal, wybuch;
	strzal.setBuffer( strzal_buf );
	wybuch.setBuffer( wybuch_buf );

	sf::Music path;
	if( !path.openFromFile( "Dzwieki/path.wav" ) )
		return -1;
	path.setVolume( 50 );
	path.play();

	srand( time( NULL ) );
	
	vector < sf::Clock > zegary;

	wybuchy wybuchy_obiekt;
	sf::Texture tekstura_wybuchu2, tekstura_wybuchu3, tekstura_wybuchu4, tekstura_wybuchu5;
	tekstura_wybuchu2.loadFromFile( "Grafika/wybuch_animacja.png", sf::IntRect( 149, 0, 149, 109 ) );
	tekstura_wybuchu3.loadFromFile( "Grafika/wybuch_animacja.png", sf::IntRect( 298, 0, 149, 109 ) );
	tekstura_wybuchu4.loadFromFile( "Grafika/wybuch_animacja.png", sf::IntRect( 447, 0, 149, 109 ) );
	tekstura_wybuchu5.loadFromFile( "Grafika/wybuch_animacja.png", sf::IntRect( 596, 0, 149, 109 ) );

	sf::Font czcionka_go;
	if( !czcionka_go.loadFromFile( "Czcionki/arial.ttf" ) )
		return -1;
	czcionka_go.loadFromFile( "Czcionki/arial.ttf" );
	sf::Text go, wynik_t;
	go.setFont( czcionka_go );
	go.setCharacterSize( 48 );
	go.setColor( sf::Color::White );
	go.setString( "Game Over" );
	go.setPosition( 180, 180 );
	
	wynik_t.setFont( czcionka_go );
	wynik_t.setCharacterSize( 36 );
	wynik_t.setColor( sf::Color::White );
	wynik_t.setPosition( 184, 230 );

	sf::Texture statek_wybuch1, statek_wybuch2, statek_wybuch3, statek_wybuch4, statek_wybuch5;
	statek_wybuch1.loadFromFile( "Grafika/statek_wybuch.png", sf::IntRect( 0, 0, 112, 118 ) );
	statek_wybuch2.loadFromFile( "Grafika/statek_wybuch.png", sf::IntRect( 112, 0, 112, 118 ) );
	statek_wybuch3.loadFromFile( "Grafika/statek_wybuch.png", sf::IntRect( 224, 0, 112, 118 ) );
	statek_wybuch4.loadFromFile( "Grafika/statek_wybuch.png", sf::IntRect( 336, 0, 112, 118 ) );
	statek_wybuch5.loadFromFile( "Grafika/statek_wybuch.png", sf::IntRect( 448, 0, 112, 118 ) );
	sf::Sprite wybuch_statku;
	wybuch_statku.setTexture( statek_wybuch1 );

	bool game_over = false;
	bool game_over_over = false;

	int punkty = 0;


	int obrot = 0;
	while( OknoAplikacji.isOpen() )
	{
		sf::Time statek_sp = statek_z.getElapsedTime();
		sf::Time szybkostrzelnosc = clock.getElapsedTime();
		sf::Time losowanie = los.getElapsedTime();
		sf::Time gw_czas = gw.getElapsedTime();
		sf::Vector2f pozycja_statku = statek.getPosition();
		sf::Event zdarzenie;

		while( OknoAplikacji.pollEvent( zdarzenie ) )
		{
			if( zdarzenie.type == sf::Event::Closed || ( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape ) )
				OknoAplikacji.close();
		}
		if( !game_over )
		{
			if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
			statek.move( -5, 0 );

			if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
			statek.move( 5, 0 );
		}

		if( pozycja_statku.x < -30 )
			statek.setPosition( 640, 396 );

		if( pozycja_statku.x > 640 )
			statek.setPosition( -30, 396 );

		if( statek_sp.asMilliseconds() >= 0 && statek_sp.asMilliseconds() < 200 )
			statek.setTexture( tekstura_statku );

		if( statek_sp.asMilliseconds() >= 200 && statek_sp.asMilliseconds() < 400 )
			statek.setTexture( tekstura_statku2 );

		if( statek_sp.asMilliseconds() >= 400 && statek_sp.asMilliseconds() < 600 )
			statek.setTexture( tekstura_statku3 );

		if( statek_sp.asMilliseconds() >= 600 && statek_sp.asMilliseconds() < 800 )
			statek.setTexture( tekstura_statku4 );

		if( statek_sp.asMilliseconds() >= 800 )
			statek_z.restart();

		if( ( gw_czas.asMilliseconds() > 100 ) && ( gwiazdy_obiekt.gwiazdy_kontener.size() <= 100 ) )
		{
			gw.restart();
			gwiazdy_obiekt.stworz_gwiazde( ( rand() % 635 ), -58 ); 
		}

		if( ( losowanie.asMilliseconds() > 600 ) && ( pudla_obiekt.pudla_kontener.size() <= 5 ) )
		{
			los.restart();
			pudla_obiekt.stworz_pudlo( ( rand() % 564 ), -58 ); 
		}

		if( !gwiazdy_obiekt.gwiazdy_kontener.empty() )
			for( int i = 0; i < gwiazdy_obiekt.gwiazdy_kontener.size(); i++ )
				 gwiazdy_obiekt.gwiazdy_kontener[ i ].move( 0, 2 );

		if( !pudla_obiekt.pudla_kontener.empty() )
			for( int i = 0; i < pudla_obiekt.pudla_kontener.size(); i++ )
				pudla_obiekt.pudla_kontener[ i ].move( 0, 5 );

		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && szybkostrzelnosc.asMilliseconds() > 300 && !game_over && !game_over_over )
		{
			clock.restart();
			pozycja_statku = statek.getPosition();
			pociski_obiekt.stworz_pocisk( pozycja_statku.x, pozycja_statku.y );
			strzal.play();
			shoot = true;
		}
		
		if( shoot == true )
		{
			if( pociski_obiekt.pociski_kontener.empty() )
				shoot = false;
			for( int k = 0; k < pociski_obiekt.pociski_kontener.size(); k++ )
			{
				pociski_obiekt.pociski_kontener[ k ].move( 0, -5 );
			}
			for( int j = 0; j < pociski_obiekt.pociski_kontener.size(); j++ )
			{
				sf::Vector2f pozycja_pocisku = pociski_obiekt.pociski_kontener[ j ].getPosition();
				for( int i = 0; i < pudla_obiekt.pudla_kontener.size(); i++ )
				{
					sf::Vector2f pozycja_pudla = pudla_obiekt.pudla_kontener[ i ].getPosition(); //wykrywanie kolizji
					if( ( pozycja_pocisku.x >= pozycja_pudla.x ) && 
						( pozycja_pocisku.x <= pozycja_pudla.x + 76 ) && 
						( pozycja_pocisku.y >= pozycja_pudla.y ) && 
						( pozycja_pocisku.y <= pozycja_pudla.y + 57 ) )
						{
							wybuchy_obiekt.stworz_wybuch( pozycja_pudla.x, pozycja_pudla.y );
							sf::Clock wybuch_z;
							zegary.push_back( wybuch_z );
							wybuch.play();
							pociski_obiekt.pociski_kontener.erase( pociski_obiekt.pociski_kontener.begin() + j );
							pudla_obiekt.pudla_kontener.erase( pudla_obiekt.pudla_kontener.begin() + i );
							punkty++;
						}
				}
				if( pozycja_pocisku.y < -10 )
					pociski_obiekt.pociski_kontener.erase( pociski_obiekt.pociski_kontener.begin() + j );
			}
		}
		for(  int j = 0; j < zegary.size(); j++ )
		{
			sf::Time wybuch_t = zegary[ j ].getElapsedTime();
			if( wybuch_t.asMilliseconds() >= 50 && wybuch_t.asMilliseconds() < 100 )
				wybuchy_obiekt.wybuchy_kontener[ j ].setTexture( tekstura_wybuchu2 );
			if( wybuch_t.asMilliseconds() >= 100 && wybuch_t.asMilliseconds() < 150 )
				wybuchy_obiekt.wybuchy_kontener[ j ].setTexture( tekstura_wybuchu3 );
			if( wybuch_t.asMilliseconds() >= 150 && wybuch_t.asMilliseconds() < 200 )
				wybuchy_obiekt.wybuchy_kontener[ j ].setTexture( tekstura_wybuchu4 );
			if( wybuch_t.asMilliseconds() >= 200 && wybuch_t.asMilliseconds() < 250 )
				wybuchy_obiekt.wybuchy_kontener[ j ].setTexture( tekstura_wybuchu5 );
			if( wybuch_t.asMilliseconds() >= 250 )
			{
				wybuchy_obiekt.wybuchy_kontener.erase( wybuchy_obiekt.wybuchy_kontener.begin() + j );
				zegary.erase( zegary.begin() + j );
			}
		}

		for( int i = 0; i < pudla_obiekt.pudla_kontener.size(); i++ )
		{
			pozycja_statku = statek.getPosition();
			sf::Vector2f pozycja_pudla2 = pudla_obiekt.pudla_kontener[ i ].getPosition();
			if( pozycja_pudla2.y > 480 )
				pudla_obiekt.pudla_kontener.erase( pudla_obiekt.pudla_kontener.begin() + i );

			if( pozycja_pudla2.x >= pozycja_statku.x && 
				pozycja_pudla2.x <= pozycja_statku.x + 30 && 
				pozycja_pudla2.y >= pozycja_statku.y && 
				pozycja_pudla2.y <= pozycja_statku.y + 78 )
			{
				ostringstream ss;
				ss << "Wynik: " << punkty;
				string wynik = ss.str();
				wynik_t.setString( wynik );
				statek_w.restart();
				wybuch.play();
				game_over = true;
			}
		}

		for( int l = 0; l < gwiazdy_obiekt.gwiazdy_kontener.size(); l++ )
		{
			sf::Vector2f pozycja_gwiazdy = gwiazdy_obiekt.gwiazdy_kontener[ l ].getPosition();
			if( pozycja_gwiazdy.y > 480 )
				gwiazdy_obiekt.gwiazdy_kontener.erase( gwiazdy_obiekt.gwiazdy_kontener.begin() + l );
		}

		OknoAplikacji.clear( sf::Color::Black );

		for( int k = 0; k < gwiazdy_obiekt.gwiazdy_kontener.size(); k++ )
			OknoAplikacji.draw( gwiazdy_obiekt.gwiazdy_kontener[ k ] );

		if( !game_over )
			OknoAplikacji.draw( statek );

		for( int i = 0; i < pudla_obiekt.pudla_kontener.size(); i++ )
			OknoAplikacji.draw( pudla_obiekt.pudla_kontener[ i ] );

		for( int j = 0; j < pociski_obiekt.pociski_kontener.size(); j++ )
			OknoAplikacji.draw( pociski_obiekt.pociski_kontener[ j ] );

		for( int m = 0; m < wybuchy_obiekt.wybuchy_kontener.size(); m++ )
			OknoAplikacji.draw( wybuchy_obiekt.wybuchy_kontener[ m ] );

		if( game_over && !game_over_over )
		{
			OknoAplikacji.draw( wybuch_statku );
			pozycja_statku = statek.getPosition();
			wybuch_statku.setPosition( pozycja_statku.x - 38, pozycja_statku.y - 25 );
			sf::Time statek_wt = statek_w.getElapsedTime();

			if( statek_wt.asMilliseconds() < 50 )
				OknoAplikacji.draw( wybuch_statku );
			if( statek_wt.asMilliseconds() >= 100 && statek_wt.asMilliseconds() < 200 )
				wybuch_statku.setTexture( statek_wybuch2 );
			if( statek_wt.asMilliseconds() >= 200 && statek_wt.asMilliseconds() < 300 )
				wybuch_statku.setTexture( statek_wybuch3 );
			if( statek_wt.asMilliseconds() >= 300 && statek_wt.asMilliseconds() < 400 )
				wybuch_statku.setTexture( statek_wybuch4 );
			if( statek_wt.asMilliseconds() >= 400 && statek_wt.asMilliseconds() < 500 )
				wybuch_statku.setTexture( statek_wybuch5 );
			if( statek_wt.asMilliseconds() >= 500 )
				game_over_over = true;

			OknoAplikacji.draw( go );
			OknoAplikacji.draw( wynik_t );
		}

		if( game_over_over )
		{
			OknoAplikacji.draw( go );
			OknoAplikacji.draw( wynik_t );
			sf::Time statek_wt = statek_w.getElapsedTime();
			if( statek_wt.asSeconds() >= 6 )
				OknoAplikacji.close();
		}

		OknoAplikacji.display();
	}
	return 0;
}
