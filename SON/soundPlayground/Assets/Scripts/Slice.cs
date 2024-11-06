using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SchedEvent: MonoBehaviour {
    private AudioSource head;
    private AudioSource tail;
    private AudioSource casing;
    //public AudioClip sound01, sound02;
    public AudioClip[] pcmDataHeads, pcmDataTails, pcmDataCasing;

    [Range(0.001f, 0.03f), Tooltip("Overlap time in ms")]
    public float overlapTime = 0.01f;
    private int nHeads, nTails, nCasing;


    void Awake(){
        nHeads = pcmDataHeads.Length;
        nTails = pcmDataTails.Length;
        nCasing = pcmDataCasing.Length;
        head = gameObject.AddComponent<AudioSource>();        
        tail = gameObject.AddComponent<AudioSource>();       
        casing = gameObject.AddComponent<AudioSource>();
    }

    void Start(){
        
        for (int i = 0; i < nHeads; i++){
            FadeIn(pcmDataHeads[i], 0, overlapTime);
        }

        for (int i = 0; i < nTails; i++){
            Fadeout(pcmDataTails[i], 0, overlapTime);
        }
    }

    // Update is called once per frame
    void Update(){
        if (Input.GetKeyDown(KeyCode.Alpha3)) {
            int h = Random.Range(0, nHeads), t = Random.Range(0, nTails), c = Random.Range(0, pcmDataCasing.Length);
            head.clip = pcmDataHeads[h];
            tail.clip = pcmDataTails[t];
            casing.clip = pcmDataCasing[c];
            double clipLength = (double) head.clip.samples / head.pitch;
            
            int sRATE = AudioSettings.outputSampleRate;
            Debug.Log($"head {h} length {clipLength}  p tail {t}  sRATE: {sRATE}");

            head.Play();
            tail.PlayScheduled(AudioSettings.dspTime+clipLength/sRATE);
            casing.PlayScheduled((head.clip.length + tail.clip.length) + zRandom.Range(-1.0f, 1.0f));
        }
    }


    void FadeIn(AudioClip clip, float startTime, float duration){
        float[] arrayedClip = new float[Mathf.FloorToInt(clip.frequency * duration)];
        clip.GetData(arrayedClip, Mathf.FloorToInt(clip.frequency * startTime));

        //fade in using sqrt curve
        for (int i = 0; i < arrayedClip.Length; i++){
            arrayedClip[i] *= Mathf.Sqrt((float)i / arrayedClip.Length);
        }

        clip.SetData(arrayedClip, Mathf.FloorToInt(clip.frequency * startTime));
    }

    void Fadeout(AudioClip clip, float startTime, float duration){
        float[] arrayedClip = new float[Mathf.FloorToInt(clip.frequency * duration)];
        clip.GetData(arrayedClip, Mathf.FloorToInt(clip.frequency * startTime));

        //fade in using sqrt curve
        for (int i = 0; i < arrayedClip.Length; i++){
            arrayedClip[i] *= Mathf.Sqrt((arrayedClip.Length - (float) i) / arrayedClip.Length);
        }

        clip.SetData(arrayedClip, Mathf.FloorToInt(clip.frequency * startTime));
    }
}
