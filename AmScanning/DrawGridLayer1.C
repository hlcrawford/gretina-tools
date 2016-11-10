{

  gROOT->ProcessLine(".x Q4Time0.C");
  gROOT->ProcessLine(".x Q4Time1.C");
  gROOT->ProcessLine(".x Q4Time2.C");
  gROOT->ProcessLine(".x Q4Time3.C");
  gROOT->ProcessLine(".x Q4Time4.C");
  gROOT->ProcessLine(".x Q4Time5.C");
  gROOT->ProcessLine(".x Q4TimeAll.C");

  gStyle->SetOptStat(0);

  TCanvas *mine = new TCanvas();

  Double_t t0Cnts[2000] = {0};
  Double_t t1Cnts[2000] = {0};
  Double_t t2Cnts[2000] = {0};
  Double_t t3Cnts[2000] = {0};
  Double_t t4Cnts[2000] = {0};
  Double_t t5Cnts[2000] = {0};

  Int_t tIndex = 0;
  Int_t started = 0;

  for (Int_t i=10; i<timeAll->GetNbinsX(); i++) {
    if (tIndex < 2000 && timeAll->GetBinContent(i) > 0) {
      started = 1;
      if (time0->GetBinContent(i) > 0) {
	t0Cnts[tIndex] += time0->GetBinContent(i);
      }
      if (time1->GetBinContent(i) > 0) {
       	t1Cnts[tIndex] += time1->GetBinContent(i);
      } 
      if (time2->GetBinContent(i) > 0) {
       	t2Cnts[tIndex] += time2->GetBinContent(i);
      } 
      if (time3->GetBinContent(i) > 0) {
       	t3Cnts[tIndex] += time3->GetBinContent(i);
      }
      if (time4->GetBinContent(i) > 0) {
       	t4Cnts[tIndex] += time4->GetBinContent(i);
      }
      if (time5->GetBinContent(i) > 0) {
       	t5Cnts[tIndex] += time5->GetBinContent(i);
      }
    }
  
    if (started) {
      tIndex++;
    }
  }

  Double_t xTime[2000] = {0.};
  Double_t yTime[2000] = {0.};
  Int_t index = 0;
  for (Int_t iy = -90; iy<=-9; iy += 3) {
    for (Int_t ix = -48; ix<=48; ix += 3) {
      xTime[index] = ix;
      yTime[index] = iy;
      index++;
    }
  }
  printf("Indexed (x,y) for %d points\n", index);
  for (Int_t i=0; i<index; i++) {
    printf("%d %d %d\n", i, xTime[i], yTime[i]);
  }

  TH2F *twoD0 = new TH2F("twoD0", "twoD0", 32, -48, 48, 27, -90, -9); 
  TH2F *twoD1 = new TH2F("twoD1", "twoD1", 32, -48, 48, 27, -90, -9); 
  TH2F *twoD2 = new TH2F("twoD2", "twoD2", 32, -48, 48, 27, -90, -9); 
  TH2F *twoD3 = new TH2F("twoD3", "twoD3", 32, -48, 48, 27, -90, -9); 
  TH2F *twoD4 = new TH2F("twoD4", "twoD4", 32, -48, 48, 27, -90, -9); 
  TH2F *twoD5 = new TH2F("twoD5", "twoD5", 32, -48, 48, 27, -90, -9); 

  for (Int_t m=0; m<index; m++) {
    twoD0->Fill(xTime[m], yTime[m], t0Cnts[m]);
    twoD1->Fill(xTime[m], yTime[m], t1Cnts[m]);
    twoD2->Fill(xTime[m], yTime[m], t2Cnts[m]);
    twoD3->Fill(xTime[m], yTime[m], t3Cnts[m]);
    twoD4->Fill(xTime[m], yTime[m], t4Cnts[m]);
    twoD5->Fill(xTime[m], yTime[m], t5Cnts[m]);
  }

  mine->cd();
  twoD0->SetLineColor(kBlue+2);  twoD1->SetLineColor(kMagenta-3);
  twoD2->SetLineColor(kRed+1);  twoD3->SetLineColor(kOrange+1);
  twoD4->SetLineColor(kGreen+1);  twoD5->SetLineColor(kAzure+2);
  twoD0->Draw("BOX"); 
  twoD1->Draw("BOX same");
  twoD2->Draw("BOX same");
  twoD3->Draw("BOX same");
  twoD4->Draw("BOX same");
  twoD5->Draw("BOX same");
  mine->SaveAs("TwoDMap.C");

  Double_t xToPlot[50] = {0};
  Double_t y0ToPlot[50] = {0};
  Double_t y1ToPlot[50] = {0};
  Double_t y2ToPlot[50] = {0};
  Double_t y3ToPlot[50] = {0};
  Double_t y4ToPlot[50] = {0};
  Double_t y5ToPlot[50] = {0};

  for (Int_t iy = -90; iy <= 9; iy += 3) {
    Int_t n=0;
    for (Int_t m=0; m<50; m++) { 
      xToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
    }
    for (Int_t ix = -48; ix <= 48; ix += 3) {
      for (Int_t m = 0; m<index; m++) {
	if (xTime[m] == ix && yTime[m] == iy) {
	  xToPlot[n] = xTime[m];
	  y0ToPlot[n] = t0Cnts[m];
	  y1ToPlot[n] = t1Cnts[m];
	  y2ToPlot[n] = t2Cnts[m];
	  y3ToPlot[n] = t3Cnts[m];
	  y4ToPlot[n] = t4Cnts[m];
	  y5ToPlot[n] = t5Cnts[m];
	  n++;
	}
      }
    }
    TGraph *graph0 = new TGraph(n, xToPlot, y0ToPlot);
    TGraph *graph1 = new TGraph(n, xToPlot, y1ToPlot);
    TGraph *graph2 = new TGraph(n, xToPlot, y2ToPlot);
    TGraph *graph3 = new TGraph(n, xToPlot, y3ToPlot);
    TGraph *graph4 = new TGraph(n, xToPlot, y4ToPlot);
    TGraph *graph5 = new TGraph(n, xToPlot, y5ToPlot);

    graph0.GetYaxis().SetRangeUser(0, 1200);
    graph0.SetLineColor(kBlue+2);
    graph1.SetLineColor(kMagenta-3);
    graph2.SetLineColor(kRed+1);
    graph3.SetLineColor(kOrange+1);
    graph4.SetLineColor(kGreen+1);
    graph5.SetLineColor(kAzure+2);
    graph0.SetLineWidth(2);
    graph1.SetLineWidth(2);
    graph2.SetLineWidth(2);
    graph3.SetLineWidth(2);
    graph4.SetLineWidth(2);
    graph5.SetLineWidth(2);

    char str[300];
    sprintf(str, "y = %d", iy);
    graph0->SetTitle(str);
    graph0->Draw("A*L");
    graph1->Draw("same*L");
    graph2->Draw("same*L");
    graph3->Draw("same*L");
    graph4->Draw("same*L");
    graph5->Draw("same*L");
    
    sprintf(str, "Y%d.C", iy);
    mine->SaveAs(str);
  }


  for (Int_t ix = -48; ix <= 48; ix += 3) {
    Int_t n=0;
    for (Int_t m=0; m<50; m++) { 
      xToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
      y0ToPlot[m] = 0;
    }
    for (Int_t iy = -90; iy <= 9; iy += 3) {
      for (Int_t m = 0; m<index; m++) {
	if (xTime[m] == ix && yTime[m] == iy) {
	  xToPlot[n] = yTime[m];
	  y0ToPlot[n] = t0Cnts[m];
	  y1ToPlot[n] = t1Cnts[m];
	  y2ToPlot[n] = t2Cnts[m];
	  y3ToPlot[n] = t3Cnts[m];
	  y4ToPlot[n] = t4Cnts[m];
	  y5ToPlot[n] = t5Cnts[m];
	  n++;
	}
      }
    }
    TGraph *graph0 = new TGraph(n, xToPlot, y0ToPlot);
    TGraph *graph1 = new TGraph(n, xToPlot, y1ToPlot);
    TGraph *graph2 = new TGraph(n, xToPlot, y2ToPlot);
    TGraph *graph3 = new TGraph(n, xToPlot, y3ToPlot);
    TGraph *graph4 = new TGraph(n, xToPlot, y4ToPlot);
    TGraph *graph5 = new TGraph(n, xToPlot, y5ToPlot);

    graph0.SetLineColor(kBlue+2);
    graph1.SetLineColor(kMagenta-3);
    graph2.SetLineColor(kRed+1);
    graph3.SetLineColor(kOrange+1);
    graph4.SetLineColor(kGreen+1);
    graph5.SetLineColor(kAzure+2);
    graph0.SetLineWidth(2);
    graph1.SetLineWidth(2);
    graph2.SetLineWidth(2);
    graph3.SetLineWidth(2);
    graph4.SetLineWidth(2);
    graph5.SetLineWidth(2);

    char str[300];
    sprintf(str, "x = %d", ix);
    graph0->SetTitle(str);
    graph0->Draw("A*L");
    graph1->Draw("same*L");
    graph2->Draw("same*L");
    graph3->Draw("same*L");
    graph4->Draw("same*L");
    graph5->Draw("same*L");
    
    sprintf(str, "X%d.C", ix);
    mine->SaveAs(str);
  }



}
