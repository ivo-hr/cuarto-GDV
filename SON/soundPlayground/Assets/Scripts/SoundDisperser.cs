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
}

[System.Serializable]
public class Ambience {
    public AudioClip ambientSound;
    [Range(0f, 1f)]
    public float intensity;

    [SerializeField, Tooltip("Sound groups that will be played in this ambience")]
    public List<SoundGroup> soundGroups;
}
public class SoundDisperser : MonoBehaviour {
    
    [SerializeField, Tooltip("List of sound environments that include ambience sound and sound groups")]
    public List<Ambience> soundEnvironments; //Sonido de fondo


}