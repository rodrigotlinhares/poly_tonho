#include "background.h"

//--------------------------------------------------------------------------------
background::background(unsigned int W, unsigned int H)
{
	m_W = W;
	m_H = H;
	
	m_fFrame=m_lFrame=NULL;
	numberOfFrames = 0;
}
//--------------------------------------------------------------------------------
background::~background()
{
	tFrame* currFrame=m_fFrame;
	tFrame* nextFrame;
	while(currFrame)
	{
		nextFrame=currFrame->next;
		free(currFrame->data);
		free(currFrame);
		currFrame = nextFrame;
	}
}
//--------------------------------------------------------------------------------
void background::addImage(unsigned char* data)
{	
	int frameLimit = 20;
	tFrame* newFrame = (tFrame*) calloc(1, sizeof(tFrame));
	newFrame->data = data;
	
	if(numberOfFrames > frameLimit)
	{
		tFrame* tmpFrame=m_fFrame->next;
		free(m_fFrame->data);
		free(m_fFrame);
		
		m_fFrame=tmpFrame;
		numberOfFrames--;
	}  
	
	if(m_fFrame==NULL)
	{
		m_fFrame = newFrame;
		m_lFrame = newFrame;
	}
	else
	{
		m_lFrame->next = newFrame;
		newFrame->prior = m_lFrame;
		m_lFrame = newFrame;
	}
	numberOfFrames++;
	
	if(numberOfFrames < frameLimit) return;
	
	//compute dinBack
	int sizeL = m_W*m_H*3;
	for(int i=0; i<sizeL; i+=3)
	{
		long int rr, gg, bb;
		int meanrr, meangg, meanbb;
		meanrr=meangg=meanbb=rr=gg=bb=0;
		tFrame* fr=m_fFrame;
		while(fr!=m_lFrame)
		{
			meanrr += fr->data[i];
			meangg += fr->data[i+1];
			meanbb += fr->data[i+2];
			
			rr += fabs(fr->data[i]   - m_lFrame->data[i]);
			gg += fabs(fr->data[i+1] - m_lFrame->data[i+1]);
			bb += fabs(fr->data[i+2] - m_lFrame->data[i+2]);
			
			fr = fr->next;
		}
		if(rr+gg+bb > 1000)
		{
			m_lFrame->data[i]  =(meanrr/(numberOfFrames-1)*0.9 + m_lFrame->data[i]*0.1);
			m_lFrame->data[i+1]=(meangg/(numberOfFrames-1)*0.9 + m_lFrame->data[i+1]*0.1);
			m_lFrame->data[i+2]=(meanbb/(numberOfFrames-1)*0.9 + m_lFrame->data[i+2]*0.1);
		}
	}
}   
//--------------------------------------------------------------------------------
unsigned char* background::getBackgroundModel()
{
	unsigned char* back = (unsigned char*) calloc(m_W*m_H*3, sizeof(unsigned char));
	memcpy(back,m_lFrame->data,m_W*m_H*3*sizeof(unsigned char));
	
	/*
	int sizeL = m_W*m_H*3;
	for(int i=0; i<sizeL; i+=3)
	{
		long int rr, gg, bb;
		rr=gg=bb=0;
		tFrame* fr=m_fFrame;
		while(fr)
		{
			rr += fr->data[i];
			gg += fr->data[i+1];
			bb += fr->data[i+2];
			fr = fr->next;
		}
		back[i]  =rr/numberOfFrames;
		back[i+1]=gg/numberOfFrames;
		back[i+2]=bb/numberOfFrames;
	}
	*/

	return back;
}    
//--------------------------------------------------------------------------------
    