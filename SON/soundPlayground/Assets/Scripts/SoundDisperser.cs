using System.Collections;
using System.Collections.Generic;
using UnityEngine;



[System.Serializable]
public class SoundGroup {
    [SerializeField, Tooltip("List of sounds that can be played")]
    public AudioClip[] sounds;
    [Range(0f, 1f), Tooltip("From what ambience Intensity the sound will be allowed to play")]
    public float randomThreshold;
    [Range(1f, 10f), Tooltip("Probability multiplier for this sound group in relation to the ambience Intensity")]
    public float probabilityMultiplier;

    [Tooltip("The amount of poliphony for this sound group")]
    public int poliphony;

    [HideInInspector]
    public IntermitentSound intermitentSound;
}

[System.Serializable]
public class Ambience {
    public AudioClip ambientSound;
    [Range(0f, 1f)]
    public float intensity;

    [Range(0f, 1.1f )]
    public float spatialBlend;

    [SerializeField, Tooltip("Sound groups that will be played in this ambience")]
    public List<SoundGroup> soundGroups;
}
public class SoundDisperser : MonoBehaviour {
    
    [SerializeField, Tooltip("List of sound environments that include ambience sound and sound groups")]
    public List<Ambience> soundEnvironments; //Sonido de fondo


    private AudioSource[] audioSource;

    void Start() {


        //Create an audioSource for the ambient sound in each ambience
        audioSource = new AudioSource[soundEnvironments.Count];

        for (int i = 0; i < soundEnvironments.Count; i++) {
            audioSource[i] = gameObject.AddComponent<AudioSource>();
            audioSource[i].clip = soundEnvironments[i].ambientSound;
            audioSource[i].spatialBlend = soundEnvironments[i].spatialBlend;
            audioSource[i].loop = true;
            audioSource[i].volume = soundEnvironments[i].intensity;
            
            audioSource[i].Play();

            //Create an IntermitentSound for each sound group in each ambience
            for (int j = 0; j < soundEnvironments[i].soundGroups.Count; j++) {

                soundEnvironments[i].soundGroups[j].intermitentSound = gameObject.AddComponent<IntermitentSound>();
                //Set to local variable as to ease the access
                IntermitentSound intermitentSound = soundEnvironments[i].soundGroups[j].intermitentSound;
                intermitentSound.pcmData = soundEnvironments[i].soundGroups[j].sounds;
                intermitentSound.minVol = 0.1f;
                intermitentSound.maxVol = soundEnvironments[i].intensity;
                intermitentSound.SourceVol = soundEnvironments[i].intensity;

                //Chack that poliphony is at least 1
                if (soundEnvironments[i].soundGroups[j].poliphony < 1)
                    intermitentSound.poliphony = 1;
                else 
                    intermitentSound.poliphony = soundEnvironments[i].soundGroups[j].poliphony;
            
                //Calculate the min and max time for the sound group and set it
                float minTime = (soundEnvironments[i].intensity - soundEnvironments[i].soundGroups[j].randomThreshold) 
                                * 10 / soundEnvironments[i].soundGroups[j].probabilityMultiplier;
                float maxTime = minTime + 10 / soundEnvironments[i].soundGroups[j].probabilityMultiplier;

                intermitentSound.minTime = minTime;
                intermitentSound.maxTime = maxTime;

                //Set the spatial blend
                intermitentSound.spatialBlend = soundEnvironments[i].spatialBlend;

                //Set the playmode depending on the intensity of the ambience
                if (soundEnvironments[i].intensity >= soundEnvironments[i].soundGroups[j].randomThreshold)
                    intermitentSound.enablePlayMode = true;
                else
                    intermitentSound.enablePlayMode = false;


                //Set the intermitent sound again to the sound group, just in case
                soundEnvironments[i].soundGroups[j].intermitentSound = intermitentSound;
            
            }


        }
    }


    void Update(){
        for (int i = 0; i < soundEnvironments.Count; i++) {
            audioSource[i].volume = soundEnvironments[i].intensity;
            audioSource[i].spatialBlend = soundEnvironments[i].spatialBlend;

            for (int j = 0; j < soundEnvironments[i].soundGroups.Count; j++) {

                soundEnvironments[i].soundGroups[j].intermitentSound.SourceVol = soundEnvironments[i].intensity;
                soundEnvironments[i].soundGroups[j].intermitentSound.spatialBlend = soundEnvironments[i].spatialBlend;


                if (soundEnvironments[i].intensity > soundEnvironments[i].soundGroups[j].randomThreshold) {
                    //Calculate the min and max time for the sound group and set it
                    float minTime = (soundEnvironments[i].intensity - soundEnvironments[i].soundGroups[j].randomThreshold) 
                                    * 10 / soundEnvironments[i].soundGroups[j].probabilityMultiplier;
                    float maxTime = minTime + 10 / soundEnvironments[i].soundGroups[j].probabilityMultiplier;

                    soundEnvironments[i].soundGroups[j].intermitentSound.minTime = minTime;
                    soundEnvironments[i].soundGroups[j].intermitentSound.maxTime = maxTime;

                    soundEnvironments[i].soundGroups[j].intermitentSound.enablePlayMode = true;
                } else {
                    soundEnvironments[i].soundGroups[j].intermitentSound.enablePlayMode = false;
                }
            }
        }
    }

}