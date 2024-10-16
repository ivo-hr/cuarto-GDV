using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[System.Serializable]
public class SoundGroup {
    public AudioClip[] sounds;
    [Range(0f, 1f)]
    public float randomThreshold;
    [Range(1f, 10f)]
    public float probabilityMultiplier;
}

[System.Serializable]
public class Ambience {
    public AudioClip ambientSound;
    [Range(0f, 1f)]
    public float intensity;

    public List<SoundGroup> soundGroups;
}
public class SoundDisperser : MonoBehaviour {
    
    [SerializeField]
    public List<Ambience> soundEnvironment; //Sonido de fondo


}