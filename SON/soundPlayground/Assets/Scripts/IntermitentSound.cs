
// '1' empieza la reproducción del sonido intermitente
// '2' lo para

using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class IntermitentSound : MonoBehaviour {
    [SerializeField]
    private List<AudioSource> _Speakers;  // audio source asosicada a la entidad
    [Range(0f, 1f )]
    public float minVol, maxVol, SourceVol;  // volumenes máximo y mínimo establecidos y volumen origintal del source
    public int poliphony;// numero maximo de sonidos que se pueden generar a la vez
    [Range(0f, 30f )]
    public float minTime, maxTime;  // intervalo temporal de lanzamiento
    [Range(0, 50)]
    public int distRand, maxDist;   // 
    [Range(0f, 1.1f )]
    public float spatialBlend;
    public AudioClip[] pcmData;
    public bool enablePlayMode;

    private Queue<AudioSource> availableSources;

    void Awake(){
        _Speakers = new List<AudioSource>();
        availableSources = new Queue<AudioSource>(); 

        for(int i = 0; i< poliphony; i++)
        {
            AudioSource source = gameObject.AddComponent<AudioSource>();
            source.playOnAwake = false;
            source.loop = false;
            _Speakers.Add(source);
            availableSources.Enqueue(source);
        }       
    }

    void Start() {
        foreach (var speaker in _Speakers) {
            speaker.playOnAwake = false;
            speaker.volume = 0.1f;
            speaker.loop = false;
        }
    }

    // Update is called once per frame
    void Update() {
        if (!enablePlayMode  && Input.GetKeyDown(KeyCode.Alpha1)){
            enablePlayMode = true;
            StartCoroutine("Waitforit");
        } else if (enablePlayMode && Input.GetKeyDown(KeyCode.Alpha2)){
            enablePlayMode = false;
            StopSound(); 
        }            
    }



    IEnumerator Waitforit() {
        // tiempo de espera aleatorio en el intervalo [minTime,maxTime]
        float waitTime = Random.Range(minTime, maxTime);
        Debug.Log(waitTime);

        yield return new WaitForSeconds(waitTime);   

        if (enablePlayMode && availableSources.Count > 0) {
            PlaySound();
        }      
    }

    void PlaySound() {

        if(availableSources.Count > 0){
            AudioSource currentSource = availableSources.Dequeue();
            SetSourceProperties(currentSource, pcmData[Random.Range(0, pcmData.Length)], minVol, maxVol, distRand, maxDist, spatialBlend);
            currentSource.Play();
            StartCoroutine(ReturnSourceToQueue(currentSource));
        }
        if (availableSources.Count > 0) {
            StartCoroutine(Waitforit());
        }
    }

    IEnumerator ReturnSourceToQueue(AudioSource source) {
        yield return new WaitForSeconds(source.clip.length);
        availableSources.Enqueue(source);
    }

    public void SetSourceProperties(AudioSource source, AudioClip audioData, float minVol, float maxVol,
                                    int minDist, int maxDist, float SpatialBlend) {
        source.clip = audioData;
        source.volume = SourceVol + Random.Range(minVol, maxVol);
        source.maxDistance = maxDist - Random.Range(0f, distRand);
        source.spatialBlend = spatialBlend;
    }

    void StopSound() {
        enablePlayMode = false;
        StopAllCoroutines();
        Debug.Log("stop");
    }
}    
    
