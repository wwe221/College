
public class Song {
	private String title,artist,album,composer;
	private int year,track ;
	
	public Song(String t,String a,String al, String com, int y, int tr){
	title=t;
	artist=a;
	album=al;
	composer=com;
	year=y;
	track=tr;
	}
	public String toString(){
		return ("Title:"+title+"\nArtist:"+artist+"\nAlbum:"+album+"\nComposer:"+composer+"\nYear:"+year+"\nTrack:"+track);
	}
}