using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MusicPlayer : MonoBehaviour
{
    // Start is called before the first frame update

    //Vector of all music files
    [SerializeField] 
    private List<AudioClip> musicFiles;
    [SerializeField] 
    private float crossfadeTime = 5.0f, crossfadeVolume = 1.0f;
    private bool isThereMusic = false, crossfading = false;
    private AudioSource[] audioSources;
    private int currentAudioSource = 0;
    void Start()
    {

        //Check if there are music files
        if (musicFiles.Count > 0)
            isThereMusic = true;
        else
            isThereMusic = false;

        if (isThereMusic){

            //Grab all audio sources
            audioSources = GetComponents<AudioSource>();
            //If there is not 2 audio sources, add or remove them
            if (audioSources.Length != 2){
                if (audioSources.Length > 2){
                    Debug.Log("Removing extra audio sources");
                    for (int i = 2; i < audioSources.Length; i++){
                        Destroy(audioSources[i]);
                    }
                }
                else if (audioSources.Length < 2){
                    Debug.Log("Adding enough audio sources");
                    for (int i = audioSources.Length; i < 2; i++){
                        gameObject.AddComponent<AudioSource>();
                    }
                    audioSources = GetComponents<AudioSource>();
                }
            }
            Debug.Log("Audio sources set");
            




            //Play music
            audioSources[0].clip = musicFiles[Random.Range(0, musicFiles.Count)];
            audioSources[0].Play();
            audioSources[0].volume = crossfadeVolume;
        }

    }

    // Update is called once per frame
    void Update()
    {
            //If key 1 is pressed, play random music
        if (Input.GetKeyDown(KeyCode.Alpha1) && !crossfading){
            Debug.Log("Input detected");
            StartCoroutine(CrossfadeMusic());

        }


    }



    IEnumerator CrossfadeMusic()
    {
        crossfading = true;
        
        AudioSource toFadeOut = audioSources[currentAudioSource], 
                    toFadeIn = audioSources[(currentAudioSource + 1) % 2];
        

        toFadeIn.clip = musicFiles[Random.Range(0, musicFiles.Count)];
        Debug.Log("Setting audio source 2 clip");
        toFadeIn.Play();
        float timer = 0;
        while (timer < crossfadeTime)
        {
            toFadeOut.volume = Mathf.Lerp(crossfadeVolume, 0, timer / crossfadeTime);
            toFadeIn.volume = Mathf.Lerp(0, crossfadeVolume, timer / crossfadeTime);
            timer += Time.deltaTime;
            Debug.Log("Crossfading, timer: " + timer + " volume 1:" + audioSources[0].volume + " volume 2:" + audioSources[1].volume);
            //Wait for the next frame
            yield return null;
        }
        toFadeOut.volume = 0;
        toFadeIn.volume = crossfadeVolume;

        crossfading = false;
        currentAudioSource = (currentAudioSource + 1) % 2;
    }
}
